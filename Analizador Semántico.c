#include "Analizador Semántico.h"
#include <stdlib.h>

void TS_IncrementarTope() {
    //for (int i = 0; i <= TOPE; i++)
    //    printf("\n%s  %d  %d  %d", TS[i].nombre, TS[i].tipoDato, TS[i].entrada, TS[i].parametros);
    //printf("\n----%d-----", TOPE);
    TOPE++;
    if (TOPE >= MAX_TS) {
        printf("ERROR: Tope de pila de tabla de símbolos alcanzado. Compilación abortada\n");
        exit(-1);
    }
}

// Funciona
void TS_InsertaMARCA() {
    printf("Estoy en MARCA\n");
    entradaTS input;
    input.nombre = "{";
    input.entrada = marca;
    input.tipoDato = 0;
    input.parametros = 0;
    TS[TOPE] = input;
    TS_IncrementarTope();
    if (subProg) {
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
            TS[TOPE] = input;
            TS_IncrementarTope();
        }
    }
}

// Funciona
void TS_InsertaID(YYSTYPE ident) {
    printf("Estoy en ID con %s\n", ident.lexema);
    int encontrado = 0;
    int i = TOPE-1; // Qué pasa si es el primer elemento? No puede serlo?
    while (!encontrado && TS[i].entrada != marca && i >= 0) {
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
        TS[TOPE] = input;
        TS_IncrementarTope();
    } else {
        printf("Variable %s previamente definida en línea %d\n", ident.lexema, yylineno);
    }
}

// Funciona
void TS_InsertaSUBPROG(YYSTYPE subprog) {
    printf("Estoy en SUBPROG con %s\n", subprog.lexema);
    entradaTS input;
    input.nombre = subprog.lexema;
    input.entrada = funcion;
    input.parametros = 0;
    input.tipoDato = subprog.tipo;
    TS[TOPE] = input;
    TS_IncrementarTope();
}

// Funciona
void TS_InsertaPARAMF(YYSTYPE paramf) {
    printf("Estoy en PARAMF con %s\n", paramf.lexema);
    int encontrado = 0;
    int offset = 0;
    // No entiendo por qué no puedo hacer comparaciones con operaciones sobre TOPE but ok
    int i = TOPE-1;
    int j = TOPE-1;
    while (TS[i-offset].entrada != funcion) {
        offset++;
    }
    //printf("%d  %d  %d  %d\n", TOPE, offset, i, j);
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

/*
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