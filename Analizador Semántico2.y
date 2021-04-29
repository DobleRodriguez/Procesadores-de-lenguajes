%{
    #include "Analizador Semántico.h"
    #include <stdio.h>
    #include <stdlib.h>

    extern int yylex();
    extern int yyparse();
    extern void yyerror(const char *str);
    extern FILE *yyin;
    extern int yylineno;
%}
%error-verbose


%token MAIN OPEN_BLOCK END_BLOCK SEMICOLON COMMA LEFT_PAR RIGHT_PAR ASSIGN IF ELSE WHILE VAR ENDVAR
%token SWITCH CASE BREAK RETURN ELEM_TYPE READ WRITE INCR DECR AHEADBACK UNARY_OP TERNARY
%token BIN_TER BOOL_VAR INT_VAR FLOAT_VAR CHAR_VAR LIST STRING ID LEFT_BRACK RIGHT_BRACK COLON DEFAULT
%token LOGIC_OR LOGIC_AND BIT_OR XOR BIT_AND EQ_NEQ VALUE_COMP ADD_SUB MULT MULT_OPS LIST_HEAD

%left LOGIC_OR
%left LOGIC_AND
%left BIT_OR
%left XOR
%left BIT_AND
%left EQ_NEQ
%left VALUE_COMP
%left ADD_SUB
%left MULT MULT_OPS BIN_TER
%right UNARY_OP
%right DECR
%right INCR
%left L_DECR
%left L_INCR
%left RIGHT_BRACK LEFT_BRACK

%start Programa
%%
Programa                    :   Cabecera_programa Bloque;
Bloque                      :   OPEN_BLOCK          { TS_InsertaMARCA(); }
                                VAR
                                Variables_locales
                                ENDVAR
                                Declar_de_subprogs
                                Sentencias
                                END_BLOCK           { TS_VaciarENTRADAS(); }
                            |   OPEN_BLOCK          { TS_InsertaMARCA(); } 
                                Declar_de_subprogs
                                Sentencias
                                END_BLOCK           { TS_VaciarENTRADAS(); };
Declar_de_subprogs          :   Declar_subprog Declar_de_subprogs
                            |   ;
Declar_subprog              :   Cabecera_subprog    { subProg = 1; }
                                Bloque              { subProg = 0; };
Cabecera_programa           :   Tipo MAIN LEFT_PAR Lista_parametros RIGHT_PAR
                            |   MAIN LEFT_PAR Lista_parametros RIGHT_PAR;
Variables_locales           :   Variables_locales Cuerpo_declar_variables
                            |   ;
Cuerpo_declar_variables     :   Tipo Lista_identificador SEMICOLON  
                            |   error;
Lista_identificador         :   Lista_identificador COMMA ID    { TS_InsertaID($3); }
                            |   ID                              { TS_InsertaID($1); };
Cabecera_subprog            :   Tipo ID LEFT_PAR Lista_parametros RIGHT_PAR { TS_InsertaSUBPROG($2); }
                            |   error;
Lista_parametros            :   Lista_parametros COMMA Parametros
                            |   Parametros
                            |   
                            |   error;
Parametros                  :   Tipo ID     { TS_InsertaPARAMF($2); };
Sentencias                  :   Sentencias Sentencia
                            |   ;
Sentencia                   :   Bloque
                            |   Sentencia_asignacion
                            |   Sentencia_entrada
                            |   Sentencia_salida
                            |   Sentencia_return
                            |   Sentencia_switch
                            |   ID INCR SEMICOLON %prec L_INCR  { $$ = numericUnary($1); }
                            |   ID DECR SEMICOLON %prec L_DECR  { $$ = numericUnary($1); }
                            |   INCR ID SEMICOLON               { $$ = numericUnary($2); }
                            |   DECR ID SEMICOLON               { $$ = numericUnary($2); }
                            |   LIST_HEAD ID SEMICOLON          { $$ = listUnary($2); }
                            |   ID AHEADBACK SEMICOLON          { $$ = listUnary($1); }
                            |   Sentencia_break
                            |   Sentencia_if
                            |   Sentencia_while;
Sentencia_asignacion        :   ID ASSIGN Expresion SEMICOLON  
Sentencia_if                :   IF LEFT_PAR Expresion RIGHT_PAR Sentencia { TS_CondicionBooleana($3); } 
                            |   IF LEFT_PAR Expresion RIGHT_PAR Sentencia ELSE Sentencia {TS_CondicionBooleana($3) ; TS_CondicionBooleana($7)};
Sentencia_while             :   WHILE LEFT_PAR Expresion RIGHT_PAR Sentencia { TS_CondicionBooleana($3); };
Sentencia_entrada           :   READ Lista_expresiones_o_cadena SEMICOLON;
Sentencia_salida            :   WRITE Lista_expresiones_o_cadena SEMICOLON;
Sentencia_return            :   RETURN Expresion SEMICOLON;
Sentencia_switch            :   SWITCH Bloque_switch;
Sentencia_break             :   BREAK SEMICOLON;
Bloque_switch               :   OPEN_BLOCK Sentencias_case END_BLOCK;
Sentencias_case             :   CASE Expresion COLON Bloque Sentencias_case
                            |   DEFAULT COLON Bloque Sentencias_case
                            |   ;
Lista_expresiones_o_cadena  :   Lista_expresiones_o_cadena COMMA Expresion
                            |   Lista_expresiones_o_cadena COMMA STRING
                            |   Expresion
                            |   STRING;
Expresion                   :   LEFT_PAR Expresion RIGHT_PAR
                            |   UNARY_OP Expresion
                            |   Expresion LOGIC_OR Expresion    { $$ = booleanCheck($1, $3); }
                            |   Expresion LOGIC_AND Expresion   { $$ = booleanCheck($1, $3); }
                            |   Expresion XOR Expresion         { $$ = booleanCheck($1, $3); }
                            |   Expresion BIT_OR Expresion      { $$ = booleanCheck($1, $3); }
                            |   Expresion BIT_AND Expresion     { $$ = booleanCheck($1, $3); }
                            |   ADD_SUB Expresion %prec UNARY_OP    { $$ = numericUnary($2); }
                            |   MULT Expresion %prec UNARY_OP       { $$ = numericUnary($2); }
                            |   Expresion ADD_SUB Expresion     { $$ = numericCheck($1, $3); }
                            |   Expresion MULT Expresion        { $$ = numericCheck($1, $3); }
                            |   Expresion MULT_OPS Expresion    { $$ = numericCheck($1, $3); }
                            |   Expresion BIN_TER Expresion     
                            |   Expresion EQ_NEQ Expresion      { $$ = booleanResult($1, $3); }
                            |   Expresion VALUE_COMP Expresion  { $$ = booleanResult($1, $3); }
                            |   Expresion DECR Expresion %prec MULT { $$ = listCheck($1, $3); }
                            |   Expresion INCR Expresion TERNARY Expresion %prec MULT   { $$ = listTernary($1, $3, $5); }
                            |   ID
                            |   Funcion
                            |   Constantes
                            |   Constante_lista
                            |   error;
Constantes                  :   INT_VAR
                            |   BOOL_VAR
                            |   CHAR_VAR
                            |   FLOAT_VAR;
Constante_lista             :   LEFT_BRACK Lista_int RIGHT_BRACK SEMICOLON
                            |   LEFT_BRACK Lista_bool RIGHT_BRACK SEMICOLON
                            |   LEFT_BRACK Lista_float RIGHT_BRACK SEMICOLON
                            |   LEFT_BRACK Lista_char RIGHT_BRACK SEMICOLON
                            |   LEFT_BRACK RIGHT_BRACK SEMICOLON;
Lista_int                   :   Lista_int COMMA INT_VAR
                            |   INT_VAR;
Lista_bool                  :   Lista_bool COMMA BOOL_VAR
                            |   BOOL_VAR;
Lista_float                 :   Lista_float COMMA FLOAT_VAR
                            |   FLOAT_VAR;
Lista_char                  :   Lista_char COMMA CHAR_VAR
                            |   CHAR_VAR;
Funcion                     :   ID LEFT_PAR Lista_expresiones RIGHT_PAR
                            |   ID LEFT_PAR RIGHT_PAR;
Lista_expresiones           :   Lista_expresiones COMMA Expresion
                            |   Expresion;
Tipo                        :   ELEM_TYPE           {tipoTmp = $1.tipo; }
                            |   LIST ELEM_TYPE      {tipoTmp = lista;   };   
%%
void yyerror(const char *str) {
    printf("\nError sintáctico en la línea %d: %s\n", yylineno, str);
}

int main (int argc, char** argv) {

    // Si no se envía un argumento (fichero) da error
	if (argc <= 1) {

        printf("\nError al ejecutar la aplicación...\n");
        printf("Uso: %s nombre_fichero_fuente\n", argv[0]);

		exit(-1);

	}

    // Abrimos el fichero 
    yyin = fopen(argv[1], "r");

    // Si "yyin" es nulo no se ha podido abrir
    if (yyin == NULL) {

        printf ("\nError al abrir el fichero %s\n", argv[1]);

        exit (-2);

    }

    printf("Leyendo %s\n", argv[1]);
    // Llamamos al analizador léxico para comenzar el análisis

    // Ejecutamos hasta que terminemos de analizar todo el archivo
    do {
        yyparse();
    } while (!feof(yyin));

	exit(1);

}
