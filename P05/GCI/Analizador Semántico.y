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
%define parse.trace

%token MAIN OPEN_BLOCK END_BLOCK SEMICOLON COMMA LEFT_PAR RIGHT_PAR ASSIGN IF ELSE WHILE VAR ENDVAR
%token SWITCH CASE BREAK RETURN ELEM_TYPE READ WRITE INCR DECR AHEADBACK UNARY_OP TERNARY
%token BOOL_VAR INT_VAR FLOAT_VAR CHAR_VAR LIST STRING ID LEFT_BRACK RIGHT_BRACK COLON DEFAULT
%token LOGIC_OR LOGIC_AND BIT_OR XOR BIT_AND EQ_NEQ VALUE_COMP ADD_SUB MULT LIST_HEAD

%left LOGIC_OR
%left LOGIC_AND
%left BIT_OR
%left XOR
%left BIT_AND
%left EQ_NEQ
%left VALUE_COMP
%left ADD_SUB
%left MULT LIST_BIN
%right NOT LIST_UNARY
%right DECR
%right INCR
%left L_DECR
%left L_INCR

%start Programa
%%
Programa                    :   { GCI_GeneraFichero(); }
                                Cabecera_programa
                                { mainVar = 1; }
                                Bloque
                                { GCI_CerrarFichero(); }
                            ;   
Bloque                      :   OPEN_BLOCK          
                                { TS_InsertaMARCA(); }
                                VAR Variables_locales ENDVAR
                                { GCI_Cabecera(mainVar); GCI_InicioBloque(); mainVar = 0; }
                                Declar_de_subprogs Sentencias END_BLOCK 
                                { GCI_FinBloque(); TS_VaciarENTRADAS(); }
                            |   OPEN_BLOCK          
                                { TS_InsertaMARCA(); GCI_Cabecera(mainVar); GCI_InicioBloque(); mainVar = 0;}
                                Declar_de_subprogs Sentencias END_BLOCK
                                { GCI_FinBloque(); TS_VaciarENTRADAS(); }
                            ;   
Declar_de_subprogs          :   Declar_subprog Declar_de_subprogs
                            |   ;
Declar_subprog              :   Cabecera_subprog    
                                { subProg = 1; }
                                Bloque              
                                { subProg = 0; }
                            ;   
Cabecera_programa           :   Tipo MAIN LEFT_PAR Lista_parametros RIGHT_PAR   
                            |   MAIN LEFT_PAR Lista_parametros RIGHT_PAR
                            ;
Variables_locales           :   Variables_locales Cuerpo_declar_variables
                            |   
                            ;   
Cuerpo_declar_variables     :   Tipo Lista_identificador SEMICOLON  
                            |   error
                            ;   
Lista_identificador         :   Lista_identificador COMMA ID    
                                { TS_InsertaID($3); }
                            |   ID                              
                                { TS_InsertaID($1); }
                            ;   
Cabecera_subprog            :   Tipo ID                              
                                { TS_InsertaSUBPROG($2); }
                                LEFT_PAR 
                                Lista_parametros RIGHT_PAR
                            |   error
                            ;   
Lista_parametros            :   Lista_parametros COMMA Parametros
                            |   Parametros
                            |   
                            |   error
                            ;   
Parametros                  :   Tipo ID     
                                { TS_InsertaPARAMF($2); }
                            ;   
Sentencias                  :   Sentencias Sentencia
                            |   ;
Sentencia                   :   Bloque
                            |   Sentencia_asignacion
                            |   Sentencia_entrada
                            |   Sentencia_salida
                            |   Sentencia_return
                            |   Sentencia_switch
                            |   LIST_HEAD Ident SEMICOLON     
                                { TS_CheckLista($2); }                    
                            |   Ident AHEADBACK SEMICOLON 
                                { TS_CheckLista($1); }                        
                            |   Sentencia_break
                            |   Sentencia_if
                            |   Sentencia_while
                            ;   
Sentencia_asignacion        :   Ident 
                                { GCI_InicioBloque(); }
                                ASSIGN Expresion SEMICOLON  
                                { TS_MismoTipo($1, $4); GCI_Asignacion($1, $4); GCI_FinBloque();}
                            ;   
Sentencia_if                :   IF LEFT_PAR Expresion RIGHT_PAR Sentencia  
                                { TS_CheckBooleano($3); }
                            |   IF LEFT_PAR Expresion RIGHT_PAR Sentencia ELSE Sentencia 
                                { TS_CheckBooleano($3); }
                            ;   
Sentencia_while             :   WHILE LEFT_PAR Expresion RIGHT_PAR Sentencia
                                { TS_CheckBooleano($3); }
                            ;   
Sentencia_entrada           :   READ Ident SEMICOLON
                                { GCI_Read($2); }
                            ;   
Sentencia_salida            :   WRITE Lista_expresiones_o_cadena SEMICOLON
                                { GCI_WriteNewline(); }
                            ;   
Sentencia_return            :   RETURN Expresion SEMICOLON
                                { $$ = TS_TipoRetorno($2); }
                            ;   
Sentencia_switch            :   SWITCH Bloque_switch
                            ;   
Sentencia_break             :   BREAK SEMICOLON
                            ;   
Bloque_switch               :   OPEN_BLOCK Sentencias_case END_BLOCK
                            ;   
Sentencias_case             :   CASE Expresion COLON Bloque Sentencias_case
                            |   DEFAULT COLON Bloque Sentencias_case
                            |   
                            ;   
Lista_expresiones_o_cadena  :   Lista_expresiones_o_cadena COMMA Expresion
                                { GCI_Write($3, 0); }
                            |   Lista_expresiones_o_cadena COMMA STRING
                                { GCI_Write($3, 1); }
                            |   Expresion
                                { GCI_Write($1, 0); }
                            |   STRING
                                { GCI_Write($1, 1); }
                            ;   
Expresion                   :   LEFT_PAR Expresion RIGHT_PAR
                                { $$ = $2; }
                            |   NOT Expresion
                                { $$ = TS_AsignarBoolUnario($1, $2); }
                            |   Expresion LOGIC_OR Expresion        
                                { $$ = TS_AsignarBoolBinario($1, $2, $3); }  
                            |   Expresion LOGIC_AND Expresion       
                                { $$ = TS_AsignarBoolBinario($1, $2, $3); } 
                            |   Expresion XOR Expresion             
                                { $$ = TS_AsignarBoolBinario($1, $2, $3); }
                            |   Expresion BIT_OR Expresion          
                                { $$ = TS_AsignarBoolBinario($1, $2, $3); }
                            |   Expresion BIT_AND Expresion         
                                { $$ = TS_AsignarBoolBinario($1, $2, $3); }
                            |   ADD_SUB Expresion %prec NOT    
                                { $$ = TS_AsignarNumUnario($1, $2); }
                            |   Expresion ADD_SUB Expresion    
                                { $$ = TS_AsignarNumBinario($1, $2, $3); }
                            |   Expresion MULT Expresion 
                                { $$ = TS_AsignarNumBinario($1, $2, $3); }
                            |   Expresion EQ_NEQ Expresion          
                                { $$ = TS_AsignarComp($1, $2, $3); }
                            |   Expresion VALUE_COMP Expresion      
                                { $$ = TS_AsignarComp($1, $2, $3); }
                            |   Expresion LIST_BIN Expresion
                                { $$ = TS_AsignarListBinario($1, $2, $3); }       
                            |   LIST_UNARY Expresion
                                { $$ = TS_AsignarListUnario($1, $2); }
                            |   Expresion DECR Expresion %prec MULT 
                                { $$ = TS_AsignarListBinario($1, $2, $3); }
                            |   Expresion INCR Expresion TERNARY Expresion %prec MULT
                                { $$ = TS_AsignarListTernario($1, $3,   $5); } 
                            |   Ident
                                { printf("A\n"); $$ = $1; }                                
                            |   Funcion
                                { printf("B\n"); $$ = $1; }                                    
                            |   Constantes  
                                { printf("C\n"); $$ = $1; }
                            |   error
                            ;   
Constantes                  :   Const_elem
                            |   Const_lista
Const_elem                  :   INT_VAR
                            |   BOOL_VAR
                            |   CHAR_VAR
                            |   FLOAT_VAR
                            ;   
Const_lista                 :   LEFT_BRACK Lista_expresiones RIGHT_BRACK
                            ;
Funcion                     :   Cabecera_func Lista_expresiones RIGHT_PAR
                                { TS_CheckFunc($1); nparams = 0; }
                            |   Cabecera_func RIGHT_PAR
                                { TS_CheckFunc($1); nparams = 0; }
                            ;  
Cabecera_func               :   IdFun LEFT_PAR
                                { func = $1; }
                            ;
Lista_expresiones           :   Lista_expresiones COMMA Expresion
                                { nparams++; TS_CheckParam($3);  }
                            |   Expresion
                                { nparams++; TS_CheckParam($1); }
                            ;   
Tipo                        :   ELEM_TYPE           
                                { tipoTmp = $1.tipo; list = 0; }
                            |   LIST ELEM_TYPE      
                                { tipoTmp = $2.tipo; list = 1; }
                            ;   
Ident                       :   ID
                                { $$ = TS_BuscarID($1);}
                            ;
IdFun                       :   ID
                                { $$ = TS_BuscarFunc($1); }
                            ;
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
