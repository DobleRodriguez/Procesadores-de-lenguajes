#include "Analizador Semántico.h"
#include <stdlib.h>

void TS_IncrementarTope() {
    //for (int i = 0; i <= TOPE; i++)
    //    printf("\n%s  %d  %d  %d  %d", TS[i].nombre, TS[i].tipoDato, TS[i].entrada, TS[i].parametros, TS[i].longitud);
    //printf("\n----%d-----", TOPE);
    TOPE++;
    if (TOPE >= MAX_TS) {
        printf("ERROR: Tope de pila de tabla de símbolos alcanzado. Compilación abortada\n");
        exit(-1);
    }
}

// Funciona
void TS_InsertaMARCA() {
    //printf("Estoy en MARCA\n");
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
    //printf("Estoy en ID con %s\n", ident.lexema);
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
    } else {
        printf("Error semántico en línea %d: variable %s previamente definida\n", yylineno, ident.lexema);
    }
}

// Funciona
void TS_InsertaSUBPROG(YYSTYPE subprog) {
    //printf("Estoy en SUBPROG con %s\n", subprog.lexema);
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
    //printf("Estoy en PARAMF con %s\n", paramf.lexema);
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
    //for (int i = 0; i < TOPE; i++)
    //    printf("\n%s  %d  %d  %d  %d", TS[i].nombre, TS[i].tipoDato, TS[i].entrada, TS[i].parametros, TS[i].longitud);
    //printf("\n----%d-----", TOPE);
}

YYSTYPE TS_BuscarID(YYSTYPE arg) {
    YYSTYPE result;
    result.tipo = desconocido;
    int i = TOPE - 1;
    //printf("buscando a %s\n", arg.lexema);
    //printf("~~~ %s\n", TS[i].nombre);
    while (i >= 0 && (strcmp(TS[i].nombre, arg.lexema) != 0)) {
        i--;
    }
    if (i < 0) {
        printf("Error semántico en línea %d: el nombre %s no ha sido declarado\n", yylineno, arg.lexema);
    } else {
        result.lexema = TS[i].nombre;
        result.tipo = TS[i].tipoDato;
        result.longitud = TS[i].longitud;
        //printf("Encontrado %s: %d %d\n", result.lexema, result.tipo, result.longitud);
    }
    return result;
}

//YYSTYPE TS_BuscarFunc(YYSTYPE arg) {
//    YYSTYPE result;
//    result.tipo = desconocido;
//    int i = TOPE - 1;
//    printf("buscando a %s\n", arg.lexema);
//    printf("~~~ %s\n", TS[i].nombre);
//    while (i >= 0 && (strcmp(TS[i].nombre, arg.lexema) != 0) && TS[i].entrada == funcion) {
//        i--;
//        if (i >= 0) printf("~~~ %s\n", TS[i].nombre);
//    }
//    if (i < 0) {
//        printf("Error semántico en línea %d: la función %s no ha sido declarada\n", yylineno, arg.lexema);
//    } else {
//        if (nparams == TS[i].parametros) {
//            result.lexema = TS[i].nombre;
//            result.tipo = TS[i].tipoDato;
//            result.longitud = TS[i].longitud;
//            printf("Encontrado %s: %d %d\n", result.lexema, result.tipo, result.longitud);
//        } else {
//            printf("Error semántico en línea %d: la función requiere %d parámetros pero se pasaron %d\n", //yylineno, TS[i].parametros, nparams);
//        }
//    }
//    return result;
//}

void TS_CheckParam(YYSTYPE arg) {
    int pos = TOPE-1;
    //printf("?????%s    %d\n",func.lexema, nparams); 
    while (TS[pos].nombre != func.lexema && pos >= 0) {
        pos--;
    }
    if (pos > 0) {
        // printf("()()()() %s\n",TS[pos+nparams].nombre);
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
    //printf("%d -- %d\n%s -- %s\n%d -- %d\n", arg1.tipo, arg2.tipo, arg1.lexema, arg2.lexema, arg1.longitud, arg2.longitud);
    //printf("%s === %s ln: %d\n", arg1.lexema, arg2.lexema, yylineno);
    if (arg1.tipo == desconocido || arg2.tipo == desconocido) {
        printf("Error semántico en línea %d: uno de los elementos de la asignación no tiene tipo válido\n", yylineno);
    } else if (arg1.tipo != arg2.tipo || (arg1.longitud >= 0 && arg2.longitud == -1) || (arg1.longitud == -1 && arg2.longitud >= 0)) {
        printf("Error semántico en línea %d: el valor asignado ha de ser del tipo declarado\n", yylineno);
    }
}

void TS_CheckBooleano(YYSTYPE arg) {
    //printf("CHECK BOOLEANO: ES %s BOOLEANO? DDDDD %d\n", arg.lexema, arg.tipo);
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

YYSTYPE TS_AsignarBoolUnario(YYSTYPE arg) {
    YYSTYPE result;
    result.tipo = desconocido;
    if (arg.tipo == booleano) {
        result.tipo = booleano;
    } else {
        printf("Error semántico en línea %d: la expresión ha de ser booleana\n", yylineno);
    }
    return result;
}

YYSTYPE TS_AsignarBoolBinario(YYSTYPE arg1, YYSTYPE op, YYSTYPE arg2) {
    YYSTYPE result;
    result.tipo = desconocido;
    //printf("%s ---- %s\n%d ---- %d\n", arg1.lexema, arg2.lexema, arg1.tipo, arg2.tipo);
    if (arg1.tipo == arg2.tipo && arg1.longitud == -1 && arg2.longitud == -1) {
        if (arg1.tipo == booleano) {
            result.tipo = booleano;
            result.lexema = "Operación booleana";
            result.longitud = -1;
        } else {
            printf("Error semántico en línea %d: las expresiones deben ser booleanas\n", yylineno);
        }
    } else {
        printf("Error semántico en línea %d: las expresiones no son de igual tipo\n", yylineno);
    }
    return result;
}

YYSTYPE TS_AsignarNumUnario(YYSTYPE op, YYSTYPE arg) {
    YYSTYPE result;
    result.tipo = desconocido;
    if (arg.tipo == entero && arg.longitud == -1) {
        result.tipo = entero;
        result.longitud = -1;
        result.lexema = "Op con entero";
    } else if (arg.tipo == real) {
        result.tipo = real;
        result.longitud = -1;
        result.lexema = "Op con real";
    } else {
        printf("Error semántico en línea %d: la expresión debe ser numérica (real o entera)\n", yylineno);
    }
    return result;
}

YYSTYPE TS_AsignarNumBinario(YYSTYPE arg1, YYSTYPE op, YYSTYPE arg2) {
    YYSTYPE result;
    result.tipo = desconocido;
    //printf("×××××× %s === %s\n××××××× %d === %d\n×××××××× %d === %d\n", arg1.lexema, arg2.lexema, arg1.tipo, arg2.tipo, arg1.longitud, arg2.longitud);
    if (arg1.tipo == arg2.tipo) {
        if (arg1.longitud >= 0) {
            if (arg2.longitud == -1) {
                result.longitud = arg1.longitud;
                result.lexema = "Lista modificada";
            } else {
                printf("Error semántico en línea %d: no se pueden operar aritméticamente dos listas\n", yylineno);
            }
        } else if (arg2.longitud >= 0 && op.atrib == 0) {
            if (arg1.longitud == -1) {
                result.longitud = arg2.longitud;
                result.lexema = "Lista modificada";
            } else {
                printf("Error semántico en línea %d: el primer parámetro no puede ser lista\n", yylineno);
            }
        } else if (arg1.longitud == -1 && arg2.longitud == -1) {
            result.longitud = -1;
            result.lexema = "Valor numérico elemental";
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
    //printf("El resultado de la operación es tipo %d\n", result.tipo);
    return result;
}

YYSTYPE TS_AsignarComp(YYSTYPE arg1, YYSTYPE op, YYSTYPE arg2) {
    //printf("\n%d --- %d\n", arg1.tipo, arg2.tipo);
    YYSTYPE result;
    result.tipo = desconocido;
    if (arg1.tipo == arg2.tipo && ((arg1.longitud >= 0 && arg2.longitud >=0) || (arg1.longitud == -1 && arg2.longitud == -1)) ) {
        result.tipo = booleano;
    } else {
        printf("Error semántico en línea %d: las expresiones no son de igual tipo\n", yylineno);
    }
    return result;
}

YYSTYPE TS_AsignarListUnario(YYSTYPE op, YYSTYPE arg) {
    YYSTYPE result;
    result.tipo = desconocido;
    if (arg.longitud >= 0) {
        if (op.atrib == 0) {
            result.tipo = entero;
            result.longitud = -1;
            result.lexema = "Longitud de lista";
        } else {
            result.tipo = arg.tipo;
            result.longitud = -1;
            result.lexema = "Elemento de lista";
        }
    } else {
        printf("Error semántico en línea %d: la expresión debe ser una lista\n", yylineno);
    }
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
                result.lexema = "Elemento de lista";
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
                result.lexema = "Lista modificada";
            } else {
                printf("Error semántico en línea %d: el segundo parámetro debe ser un entero\n", yylineno);
            }
        } else {
            if (arg2.longitud >= 0 && arg1.tipo == arg2.tipo) {
                result.tipo = arg1.tipo;
                result.longitud = arg1.longitud + arg2.longitud;
                result.lexema = "Lista modificada";
            }
        }
    } else {
        printf("Error semántico en línea %d: los parámetros deben ser lista de mismo tipo base\n", yylineno);
    }
    return result;
}

YYSTYPE TS_AsignarListTernario(YYSTYPE arg1, YYSTYPE arg2, YYSTYPE arg3) {
    //printf("****** %s    %s    %s\n", arg1.lexema, arg2.lexema, arg3.lexema);
    YYSTYPE result;
    result.tipo = desconocido;
    if (arg1.longitud >= 0 && arg2.longitud == -1 && arg3.longitud == -1) {
        if (arg2.tipo == arg1.tipo) {
            if (arg3.tipo == entero) {
                result.tipo = arg1.tipo;
                result.longitud = arg1.longitud + 1;
                result.lexema = "Lista modificada";
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

void GCI_GeneraFichero() {}

void GCI_CerrarFichero() {}

void GCI_Cabecera(int subProg) {}

void GCI_FinBloque() {}


/*
YYSTYPE TS_OpBoolBin (YYSTYPE arg1, YYSTYPE arg2) {
    YYSTYPE result;
    printf("OPBOOLBIN %d ==== %d\n", arg1.tipo, arg2.tipo);
    result.tipo = desconocido;
    if (arg1.tipo == arg2.tipo && arg1.tipo == booleano) {
        result.tipo = booleano;
    } else {
        printf("Error semántico en línea %d: los argumentos han de ser booleanos\n", yylineno);
    }
    return result;
}

YYSTYPE TS_OpNumBin (YYSTYPE arg1, YYSTYPE arg2) {
    YYSTYPE result;
    result.tipo = desconocido;
    if (arg1.tipo == arg2.tipo) {
        if (arg1.tipo == entero) {
            result.tipo = entero;
        } else if (arg1.tipo == real) {
            result.tipo = real;
        } else {
            printf("Error semántico en línea %d: los argumentos han de ser enteros o reales\n", yylineno);
        }
    } else {
        printf("Error semántico en línea %d: los argumentos han de ser de igual tipo\n", yylineno);
    }
    return result;
}


YYSTYPE TS_OpNumUnary (YYSTYPE arg) {
    YYSTYPE result;
    result.tipo = desconocido;
    if (arg.tipo == entero) {
        result.tipo = entero;
    } else if (arg.tipo == real) {
        result.tipo =  real;
    } else {
        printf("Error semántico en la línea %d: el argumento ha de ser real o entero\n", yylineno);
    }
    return result;
}

YYSTYPE TS_OpBoolUnary (YYSTYPE arg) {
    YYSTYPE result;
    result.tipo = desconocido;
    if (arg.tipo == booleano) {
        result.tipo = booleano;
    } else {
        printf("Error semántico en la línea %d: el argumento ha de ser booleano\n", yylineno);
    }
    return result;
}

void TS_BoolCondition(YYSTYPE expr) {
    if (expr.tipo != booleano) {
        printf("Error semántico en línea %d: la expresión ha de ser booleana\n", yylineno);
    } else {
        printf("Condición booleana correcta en línea %d\n", yylineno);
    }
}

void TS_TypeCondition (YYSTYPE lhs, YYSTYPE rhs) {
    if (lhs.tipo != rhs.tipo) {
        printf("Error semántico en la línea %d: a la variable deben asignarse valores del tipo declarado\n", yylineno);
    }
}

YYSTYPE TS_OpComp(YYSTYPE arg1, YYSTYPE arg2) {
    YYSTYPE result;
    result.tipo = desconocido;
    if (arg1.tipo == arg2.tipo) {
        result.tipo = booleano;
    } else {
        printf("--%d  %d--\n", arg1.tipo, arg2.tipo);
        printf("Error semántico en la línea %d: los argumentos han de ser igual tipo\n", yylineno);
    }
    return result;
}

void tsOpMul(entradaTS o1, entradaTS op, entradaTS o2, entradaTS* res){
    if (o1.tipoDato != o2.tipoDato) {
        printf("Semantic Error(%d): Expressions must be same types.", yylineno);
        return;
    }
    if (o1.tipoDato != entero && o1.tipoDato != real) {
        printf("Semantic Error%d): Invalid type in op. Both must be same.", yylineno);
        return;
    }
    if (isList(o1) && isList(o2)){
        printf("Semantic Error(%d): cannot multiply 2 lists", yylineno);
    return;
    } else {

        if (isList(o1) && !isList(o2)) {
            res->tipoDato = o1.tipoDato;
            res->dimensiones = o1.dimensiones;
        } else{
            res->tipoDato = o2.tipoDato;
            res->dimensiones = o2.dimensiones;
        }
    }
}

YYSTYPE TS_BuscarID(YYSTYPE arg) {
    int encontrado = 0;
    int i = TOPE-1; 
    YYSTYPE result;
    result.tipo = desconocido;
    while (!encontrado && i >= 0) {
        if (strcmp(TS[i].nombre, arg.lexema) == 0) {
            encontrado = 1;
        }
        i--;
    }
    if (!encontrado) {
        printf("Error semántico en línea %d: variable %s no declarada\n", yylineno, arg.lexema);
    } else {
        result.tipo = TS[i].tipoDato;
        result.lexema = TS[i].nombre;
    }
    return result;

}

int isList(entradaTS e) {
    return (e.dimensiones > 0);
}


YYSTYPE TS_AndOr (YYSTYPE arg1, YYSTYPE arg2) {
    YYSTYPE result;
    result.tipo = desconocido;
    if (arg1.tipo == arg2.tipo && arg1.tipo == booleano) {
        result.tipo = booleano;
    } else {
        printf("Error semántico en la línea: los argumentos han de ser de tipo booleano");
    }
    return result;
}

YYSTYPE TS_OpBinNumericas (YYSTYPE arg1, YYSTYPE arg2) {
    YYSTYPE result;
    result.tipo = desconocido;
    if (arg1.tipo == arg2.tipo) {
        if (arg1.tipo == entero) {
            result.tipo = entero;
        } else if (arg1.tipo == real) {
            result.tipo = real;
        } else {
            printf("Error semántico en la línea: los argumentos han de ser de tipo real o entero");
        }
    } else {
        printf("Error semántico en la línea: los argumentos han de ser de igual tipo");
    }
    return result;
}

YYSTYPE TS_OpUnNumericas (YYSTYPE arg) {
    YYSTYPE result;
    result.tipo = desconocido;
    if (arg.tipo == real) {
        result.tipo = real;
    } else if (arg.tipo == entero) {
        result.tipo = entero;
    } else {
        printf("Error semántico en la línea: el argumento ha de ser de tipo real o entero");
    }
    return result;
}

YYSTYPE TS_OpComparacion (YYSTYPE arg1, YYSTYPE arg2) {
    YYSTYPE result;
    result.tipo = desconocido;
    if (arg1.tipo == arg2.tipo) {
        result.tipo = booleano;
    } else {
        printf("Error semántico en la línea: los argumentos han de ser de igual tipo");
    }
    return result;
}

void TS_Imprimir () {
    for (int i = 0; i < TOPE; i++) {
        printf("%s  %d\n", TS[i].nombre, TS[i].tipoDato);
    }
}
*/