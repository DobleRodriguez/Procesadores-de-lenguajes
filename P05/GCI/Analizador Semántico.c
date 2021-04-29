#include "Analizador Semántico.h"
#include "dec_dat.c"
#include <stdlib.h>

FILE * file;
dtipo tipoTMP;

void TS_IncrementarTope() {
    TOPE++;
    if (TOPE >= MAX_TS) {
        printf("ERROR: Tope de pila de tabla de símbolos alcanzado. Compilación abortada\n");
        exit(-1);
    }
}

// Funciona
void TS_InsertaMARCA() {
    entradaTS input;
    input.nombre = "{";
    input.entrada = marca;
    input.tipoDato = 0;
    input.parametros = 0;
    input.longitud = 0;
    TS[TOPE] = input;
    TS_IncrementarTope();
    if (subProg) {
        TS[TOPE-1].longitud++;
        int i = TOPE-1;
        int offset = 0;
        while (TS[i-offset].entrada != funcion) {
            offset++;
        }
        for (int j = 1; j <= TS[i-offset].parametros; j++) {
            entradaTS input;
            input.nombre = TS[i-offset+j].nombre;
            input.tipoDato = TS[i-offset+j].tipoDato;
            input.entrada = variable;
            input.parametros = TS[i-offset+j].parametros;
            input.longitud = TS[i-offset+j].longitud;
            TS[TOPE] = input;
            TS_IncrementarTope();
        }
    }
}

// Funciona
void TS_InsertaID(YYSTYPE ident) {
    int encontrado = 0;
    int i = TOPE-1;
    while (i >= 0 && !encontrado && TS[i].entrada != marca) {
        if (strcmp(TS[i].nombre, ident.lexema) == 0) {
            encontrado = 1;
        }
        i--;
    }
    if (!encontrado) {
        entradaTS input;
        input.nombre = ident.lexema;
        input.entrada = variable;
        input.tipoDato = ident.tipo;
        input.parametros = 0;
        if (list) {
            input.longitud = 0;
        } else {
            input.longitud = -1;
        }
        TS[TOPE] = input;
        TS_IncrementarTope();
        GCI_DeclVariable(ident);
    } else {
        printf("Error semántico en línea %d: variable %s previamente definida\n", yylineno, ident.lexema);
    }
}

// Funciona
void TS_InsertaSUBPROG(YYSTYPE subprog) {
    int encontrado = 0;
    int i = TOPE-1;
    while (!encontrado && TS[i].entrada != marca && i >= 0) {
        if (strcmp(TS[i].nombre, subprog.lexema) == 0) {
            encontrado = 1;
        }
        i--;
    }
    if (!encontrado) {
        entradaTS input;
        input.nombre = subprog.lexema;
        input.entrada = funcion;
        input.parametros = 0;
        input.tipoDato = subprog.tipo;
        if (list) {
            input.longitud = 0;
        } else {
            input.longitud = -1;
        }
        TS[TOPE] = input;
        TS_IncrementarTope();
    }
}

// Funciona
void TS_InsertaPARAMF(YYSTYPE paramf) {
    int encontrado = 0;
    int offset = 0;
    int i = TOPE-1;
    int j = TOPE-1;
    while (TS[i-offset].entrada != funcion) {
        offset++;
    }
    while (encontrado == 0 && j > i-offset) {
        if (strcmp(TS[j].nombre, paramf.lexema) == 0 && TS[j].entrada == parametro_formal) {
            encontrado = 1;
        }
        j--;
    }
    if (!encontrado) {
        entradaTS input;
        input.nombre = paramf.lexema;
        input.entrada = parametro_formal;
        input.tipoDato = paramf.tipo;
        input.parametros = 0;
        if (list) {
            input.longitud = 0;
        } else {
            input.longitud = -1;
        }
        TS[TOPE] = input;
        TS[i-offset].parametros++;
        TS_IncrementarTope();
    } else {
        printf("Error semántico en línea %d: parámetro formal %s de función %s ya declarado\n", yylineno, paramf.lexema, TS[i-offset].nombre);
    }
}

void TS_VaciarENTRADAS() {
    TOPE--;
    while (TS[TOPE].entrada != marca && TOPE >= 0) {
        TOPE--;
    }
}

YYSTYPE TS_BuscarID(YYSTYPE arg) {
    YYSTYPE result;
    result.tipo = desconocido;
    result.lexema = arg.lexema;
    int i = TOPE - 1;
    while (i >= 0 && ((strcmp(TS[i].nombre, arg.lexema) != 0) || TS[i].entrada != variable)) {
        i--;
    }
    if (i < 0) {
        printf("Error semántico en línea %d: el nombre %s no ha sido declarado\n", yylineno, arg.lexema);
    } else {
        result.lexema = TS[i].nombre;
        result.tipo = TS[i].tipoDato;
        result.longitud = TS[i].longitud;
    }
    return result;
}

YYSTYPE TS_BuscarFunc(YYSTYPE arg) {
    YYSTYPE result;
    result.tipo = desconocido;
    result.lexema = arg.lexema;
    int i = TOPE - 1;
    while (i >= 0 && ((strcmp(TS[i].nombre, arg.lexema) != 0) || TS[i].entrada != funcion))  {
        i--;
    }
    if (i < 0) {
        printf("Error semántico en línea %d: la función %s no ha sido declarada\n", yylineno, arg.lexema);
    } else {
        result.tipo = TS[i].tipoDato;
        result.longitud = TS[i].longitud;
    }
    return result;
}

void TS_CheckParam(YYSTYPE arg) {
    int pos = TOPE-1;
    while (TS[pos].nombre != func.lexema && pos >= 0) {
        pos--;
    }
    if (pos > 0) {
        if (TS[pos+nparams].entrada == parametro_formal) {
            if (TS[pos+nparams].tipoDato != arg.tipo) {
                printf("Error semántico en línea %d: el %d° parámetro no es del tipo correcto\n", yylineno, nparams);
            }
        }
    }
}

YYSTYPE TS_CheckFunc(YYSTYPE arg) {
    YYSTYPE result;
    result.tipo = desconocido;
    int pos = TOPE-1;
    while (TS[pos].nombre != func.lexema && pos >= 0) {
        pos--;
    }
    if (pos > 0) {
        if (TS[pos].parametros == nparams) {
            result.tipo = TS[pos].tipoDato;
            result.longitud = TS[pos].longitud;
            result.lexema = TS[pos].nombre;
        } else {
            printf("Error semántico en línea %d: la función llamada no recibe el número correcto de parámetros\n", yylineno);
        }
    }
    return result;
}

void TS_MismoTipo(YYSTYPE arg1, YYSTYPE arg2) {
    if (arg1.tipo == desconocido || arg2.tipo == desconocido) {
        printf("Error semántico en línea %d: uno de los elementos de la asignación no tiene tipo válido\n", yylineno);
    } else if (arg1.tipo != arg2.tipo || (arg1.longitud >= 0 && arg2.longitud == -1) || (arg1.longitud == -1 && arg2.longitud >= 0)) {
        printf("Error semántico en línea %d: el valor asignado ha de ser del tipo declarado\n", yylineno);
    }
}

void TS_CheckBooleano(YYSTYPE arg) {
    if (arg.tipo != booleano) {
        printf("Error semántico en línea %d: la expresión ha de ser booleana\n", yylineno);
    }
}

YYSTYPE TS_TipoRetorno(YYSTYPE arg) {
    YYSTYPE result;
    result.tipo = desconocido;
    int i = TOPE - 1;
    while ((TS[i].entrada != marca || TS[i].longitud == 0) && i>=0) {
        i--;
    }
    if ( i > 0) {
        while (TS[i].entrada != funcion && i >= 0) {
            i--;
        }
    }
    dtipo tipoRetorno = TS[i].tipoDato;
    // La mult es un mecanismo para asegurarme que ambos elementos sean de igual signo
    if (tipoRetorno == arg.tipo && ((arg.longitud >= 0 && TS[i].longitud >=0) || (arg.longitud == -1 && TS[i].longitud == -1))) { 
        result.tipo = arg.tipo;
        result.lexema = arg.lexema;
        result.longitud = arg.longitud;
    } else {
        printf("Error semántico en línea %d: la función retorna un valor de otro tipo\n", yylineno);
    }
    return result;
}

YYSTYPE TS_AsignarBoolUnario(YYSTYPE op, YYSTYPE arg) {
    YYSTYPE result;
    result.tipo = desconocido;
    if (arg.tipo == booleano) {
        result.tipo = booleano;
        result.lexema = GCI_Temporal();
        result.longitud = -1;
    } else {
        printf("Error semántico en línea %d: la expresión ha de ser booleana\n", yylineno);
    }
    GCI_GenTerna(result, op, arg);
    return result;
}

YYSTYPE TS_AsignarBoolBinario(YYSTYPE arg1, YYSTYPE op, YYSTYPE arg2) {
    YYSTYPE result;
    result.tipo = desconocido;
    if (arg1.tipo == arg2.tipo && arg1.longitud == -1 && arg2.longitud == -1) {
        if (arg1.tipo == booleano) {
            result.tipo = booleano;
            result.lexema = GCI_Temporal();
            result.longitud = -1;
        } else {
            printf("Error semántico en línea %d: las expresiones deben ser booleanas\n", yylineno);
        }
    } else {
        printf("Error semántico en línea %d: las expresiones no son de igual tipo\n", yylineno);
    }
    GCI_GenCuarteto(result, arg1, op, arg2);
    return result;
}

YYSTYPE TS_AsignarNumUnario(YYSTYPE op, YYSTYPE arg) {
    YYSTYPE result;
    result.tipo = desconocido;
    if (arg.tipo == entero && arg.longitud == -1) {
        result.tipo = entero;
        result.longitud = -1;
        result.lexema = GCI_Temporal();
    } else if (arg.tipo == real) {
        result.tipo = real;
        result.longitud = -1;
        result.lexema = GCI_Temporal();
    } else {
        printf("Error semántico en línea %d: la expresión debe ser numérica (real o entera)\n", yylineno);
    }
    GCI_GenTerna(result, op, arg);
    return result;
}

YYSTYPE TS_AsignarNumBinario(YYSTYPE arg1, YYSTYPE op, YYSTYPE arg2) {
    YYSTYPE result;
    result.tipo = desconocido;
    if (arg1.tipo == arg2.tipo) {
        if (arg1.longitud >= 0) {
            if (arg2.longitud == -1) {
                result.longitud = arg1.longitud;
                result.lexema = GCI_Temporal();
            } else {
                printf("Error semántico en línea %d: no se pueden operar aritméticamente dos listas\n", yylineno);
            }
        } else if (arg2.longitud >= 0 && op.atrib == 0) {
            if (arg1.longitud == -1) {
                result.longitud = arg2.longitud;
                result.lexema = GCI_Temporal();
            } else {
                printf("Error semántico en línea %d: el primer parámetro no puede ser lista\n", yylineno);
            }
        } else if (arg1.longitud == -1 && arg2.longitud == -1) {
            result.longitud = -1;
                result.lexema = GCI_Temporal();
        } else {
            printf("Error semántico en línea %d: los operadores han de ser o 2 valores elementales o uno solo lista. El segundo parámetro puede ser lista solo en suma y multiplicación\n", yylineno);
        }
        if (arg1.tipo == entero) {
            result.tipo = entero;
        } else if (arg1.tipo == real) {
            result.tipo = real;
        } else {
            printf("Error semántico en línea %d: las expresiones deben ser numéricas (reales o enteras)\n", yylineno);
        }
    } else {
        printf("Error semántico en línea %d: las expresiones deben ser del mismo tipo\n", yylineno);
    }
    GCI_GenCuarteto(result, arg1, op, arg2);
    return result;
}

YYSTYPE TS_AsignarComp(YYSTYPE arg1, YYSTYPE op, YYSTYPE arg2) {
    YYSTYPE result;
    result.tipo = desconocido;
    if (arg1.tipo == arg2.tipo && ((arg1.longitud >= 0 && arg2.longitud >=0) || (arg1.longitud == -1 && arg2.longitud == -1)) ) {
        result.tipo = booleano;
    } else {
        printf("Error semántico en línea %d: las expresiones no son de igual tipo\n", yylineno);
    }
    GCI_GenCuarteto(result, arg1, op, arg2);
    return result;
}

YYSTYPE TS_AsignarListUnario(YYSTYPE op, YYSTYPE arg) {
    YYSTYPE result;
    result.tipo = desconocido;
    if (arg.longitud >= 0) {
        if (op.atrib == 0) {
            result.tipo = entero;
            result.longitud = -1;
            result.lexema = GCI_Temporal();
        } else {
            result.tipo = arg.tipo;
            result.longitud = -1;
            result.lexema = GCI_Temporal();
        }
    } else {
        printf("Error semántico en línea %d: la expresión debe ser una lista\n", yylineno);
    }
    GCI_GenTerna(result, op, arg);
    return result;
}

YYSTYPE TS_AsignarListBinario(YYSTYPE arg1, YYSTYPE op, YYSTYPE arg2) {
    YYSTYPE result;
    result.tipo = desconocido;
    if (arg1.longitud >= 0) {
        if (op.atrib == 0) {
            if (arg2.tipo == entero) {
                result.tipo = arg1.tipo;
                result.longitud = -1;
                result.lexema = GCI_Temporal();
            } else {
                printf("Error semántico en línea %d: el segundo parámetro debe ser un entero\n", yylineno);
            }
        } else if (op.atrib == 1 || op.atrib == 2) {
            if (arg2.tipo == entero) {
                result.tipo = arg1.tipo;
                if (op.atrib == 1) {
                    if (arg1.longitud > 0) {
                        result.longitud = arg1.longitud - 1;
                    } else {
                        result.longitud = 0;
                    }
                } else {
                    result.longitud = arg1.longitud; 
                    // Esto no hace lo que debería pero para el semántico no importa
                    // Hay que buscar el elemento en la tabla de símbolos para ver su valor real.
                }
                result.lexema = GCI_Temporal();
            } else {
                printf("Error semántico en línea %d: el segundo parámetro debe ser un entero\n", yylineno);
            }
        } else {
            if (arg2.longitud >= 0 && arg1.tipo == arg2.tipo) {
                result.tipo = arg1.tipo;
                result.longitud = arg1.longitud + arg2.longitud;
                result.lexema = GCI_Temporal();
            }
        }
    } else {
        printf("Error semántico en línea %d: los parámetros deben ser lista de mismo tipo base\n", yylineno);
    }
    GCI_GenCuarteto(result, arg1, op, arg2);
    return result;
}

YYSTYPE TS_AsignarListTernario(YYSTYPE arg1, YYSTYPE arg2, YYSTYPE arg3) {
    YYSTYPE result;
    result.tipo = desconocido;
    if (arg1.longitud >= 0 && arg2.longitud == -1 && arg3.longitud == -1) {
        if (arg2.tipo == arg1.tipo) {
            if (arg3.tipo == entero) {
                result.tipo = arg1.tipo;
                result.longitud = arg1.longitud + 1;
                result.lexema = GCI_Temporal();
            } else {
                printf("Error semántico en línea %d: la posición debe especificarse como un entero\n", yylineno);
            }
        } else {
            printf("Error semántico en línea %d: el valor introducido debe ser del tipo de la lista\n", yylineno);
        }  
    } else {
        printf("Error semántico en línea %d: el primer y sólo el primer parámetro debe ser una lista\n", yylineno);
    }
    
    return result;
}

void TS_CheckLista(YYSTYPE arg) {
    if (arg.longitud == -1) {
        printf("Error semántico en línea %d: el elemento debe ser una lista\n", yylineno);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////

void GCI_Indent() {
    for (int i=0; i < tabCount; i++) 
        fprintf(file, "\t");
}

void GCI_GeneraFichero() {
    file = fopen("CodigoIntermedio.c", "w");
    fprintf(file, "#include <stdio.h>\n#include \"dec_dat.c\"\n#include \"dec_fun.c\"\n#include <stdlib.h>\n");
}

void GCI_CerrarFichero() {
    fclose(file);
}

char* GCI_Temporal() {
    char* nombre = malloc(20);
    sprintf(nombre, "temp%d", temp);
    temp++;
    return nombre;
}

char* GCI_Etiqueta() {
    char* nombre = malloc(20);
    sprintf(nombre, "etiqueta%d", etiq);
    etiq++;
    return nombre;
}

void GCI_Cabecera(int mainVar) {
    int count = 0;
    GCI_Indent();
    if (mainVar) {
        fprintf(file, "int main()\n");
    }
}

void GCI_InicioBloque() {
    GCI_Indent();
    fprintf(file, "{\n");
    printf("%d\n", tabCount);
    tabCount++;
}

void GCI_FinBloque() {
    tabCount--;
    GCI_Indent();
    fprintf(file, "}\n");
}

void GCI_Asignacion(YYSTYPE dest, YYSTYPE arg) {
    GCI_Indent();
    fprintf(file, "%s = %s;\n", dest.lexema, arg.lexema);
}

void GCI_GenCuarteto (YYSTYPE dest, YYSTYPE arg1, YYSTYPE op, YYSTYPE arg2) {
    GCI_Indent();
    if (dest.tipo == entero || dest.tipo == booleano) {
        fprintf(file, "int %s;\n", dest.lexema);
        GCI_Indent();   
        fprintf(file, "%s = %s %s %s;\n", dest.lexema, arg1.lexema, op.lexema, arg2.lexema);
    } else if (dest.tipo == real) {
        fprintf(file, "float %s;\n", dest.lexema);
        GCI_Indent();   
        fprintf(file, "%s = %s %s %s;\n", dest.lexema, arg1.lexema, op.lexema, arg2.lexema);
    } else if (dest.tipo == caracter) {
        fprintf(file, "char %s;\n", dest.lexema);
        GCI_Indent();   
        fprintf(file, "%s = %s %s %s;\n", dest.lexema, arg1.lexema, op.lexema, arg2.lexema);
    }
}

void GCI_GenTerna (YYSTYPE dest, YYSTYPE op, YYSTYPE arg) {
    GCI_Indent();
    if (dest.tipo == entero || dest.tipo == booleano) {
        fprintf(file, "int %s;\n", dest.lexema);
        GCI_Indent();   
        fprintf(file, "%s = %s%s;\n", dest.lexema, op.lexema, arg.lexema);
    } else if (dest.tipo == real) {
        fprintf(file, "float %s;\n", dest.lexema);
        GCI_Indent();   
        fprintf(file, "%s = %s%s;\n", dest.lexema, op.lexema, arg.lexema);
    } else if (dest.tipo == caracter) {
        fprintf(file, "char %s;\n", dest.lexema);
        GCI_Indent();   
        fprintf(file, "%s = %s%s;\n", dest.lexema, op.lexema, arg.lexema);
    }
}

void GCI_DeclVariable(YYSTYPE var) {
    GCI_Indent();   
    if (var.tipo == entero || var.tipo == booleano) {
        fprintf(file, "int %s;\n", var.lexema);
    } else if (var.tipo == real) {
        fprintf(file, "float %s;\n", var.lexema);
    } else if (var.tipo == caracter) {
        fprintf(file, "char %s;\n", var.lexema);
    }

}

void GCI_Read(YYSTYPE var) {
    GCI_Indent();
    fprintf(file, "scanf(");
    if (var.tipo == entero || var.tipo == booleano) {
        fprintf(file, "\"%%d\"");
    } else if (var.tipo == real) {
        fprintf(file, "\"%%f\"");
    } else if (var.tipo == caracter) {
        fprintf(file, "\"%%c\"");
    }
    fprintf(file, ", &%s);\n", var.lexema);
}

void GCI_Write(YYSTYPE var, int string) {
    GCI_Indent();
    fprintf(file, "printf(");
    if (!string) {
        if (var.tipo == entero || var.tipo == booleano) {
            fprintf(file, "\"%%d\", %s);\n", var.lexema);
        } else if (var.tipo == real) {
            fprintf(file, "\"%%f\", %s);\n", var.lexema);
        } else if (var.tipo == caracter) {
            fprintf(file, "\"%%c\", %s);\n", var.lexema);
        }
    } else {
        fprintf(file, "\"%%s\", %s);\n", var.lexema);
    }
}

void GCI_WriteNewline() {
    GCI_Indent();
    fprintf(file, "printf(\"\\n\");\n");
}


void GCI_Lista(YYSTYPE var){
    GCI_Indent();
    if(var.longitud >= 0){
        if (var.tipo == entero){
            fprintf(file, "listOfInt %s;" , var.lexema);
        }
        else if(var.tipo == booleano){
            fprintf(file, "listOfBool %s;" , var.lexema);
        }
        else if(var.tipo == real){
            fprintf(file, "listOfFloat %s;" , var.lexema);
        }
        else{
            fprintf(file, "listOfChar %s;" , var.lexema);
        }
    }
}
/*****************************************************
******************Generación de código****************
*****************************************************/
