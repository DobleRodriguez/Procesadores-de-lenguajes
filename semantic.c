#include "semantic.h"
#include <stdlib.h>

void TS_IncrementarTope() {
    for (int i = 0; i <= TOPE; i++)
        printf("\n%s  %d  %d  %d", TS[i].nombre, TS[i].tipoDato, TS[i].entrada, TS[i].parametros);
    TOPE++;
    printf("\n----%d-----", TOPE);
    if (TOPE >= MAX_TS) {
        printf("ERROR: Tope de pila de tabla de símbolos alcanzado. Compilación abortada\n");
        exit(-1);
    }
}

// Funciona
void TS_InsertaMARCA() {
    printf("Estoy en MARCA");
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
            if (TS[i-offset].entrada == parametro_formal) {
                entradaTS input;
                input.nombre = TS[i-offset].nombre;
                input.tipoDato = TS[i-offset].tipoDato;
                input.entrada = variable;
                input.parametros = TS[i-offset].parametros;
                TS[TOPE] = input;
                TS_IncrementarTope();
            }
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
    printf("Estoy en ID con %s", ident.lexema);
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
    printf("Estoy en SUBPROG con %s", subprog.lexema);
    entradaTS input;
    input.nombre = subprog.lexema;
    input.entrada = funcion;
    input.parametros = 0;
    input.tipoDato = subprog.tipo;
    TS[TOPE] = input;
    TS_IncrementarTope();
}

// Funciona
// NO reporta error
void TS_InsertaPARAMF(YYSTYPE paramf) {
    printf("Estoy en PARAMF con %s", paramf.lexema);
    int encontrado = 0;
    int offset = 0;
    // No entiendo por qué no puedo hacer comparaciones con operaciones sobre TOPE but ok
    int i = TOPE-1;
    int j = TOPE-1;
    while (TS[i-offset].entrada != funcion) {
        offset++;
    }
    printf("%d  %d  %d  %d\n", TOPE, offset, i, j);
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
    result.tipo = desconocido;
    if (arg1.tipo == arg2.tipo && arg1.tipo == booleano) {
        result.tipo = booleano;
    } else {
        printf("Error semántico en línea %d: los argumentos han de ser booleanos\n", yylineno);
    }
    return result;
}

void TS_BoolCondition(YYSTYPE expr) {
    if (expr.tipo != booleano) {
        printf("Error semántico en línea %d: la expresión ha de ser booleana\n", yylineno);
    }
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

// Realiza la comprobación de la operación *, /

bool isList(entradaTS e){
    return (e.dimensiones > 0);
}

int equalSize(entradaTS e1, entradaTS e2){

    return (e1.dimensiones == e2.dimensiones);

}


// Realiza la comprobación de la operación !, &, ~
void tsOpUnary(entradaTS op, entradaTS o, entradaTS* res){

    if (o.tipoDato != booleano || isList(o)) {
		printf("Semantic Error(%d): Not operator expects logic expression.", yylineno);
	}

	res->tipoDato = booleano;
	res->dimensiones = 0;
}


// Realiza la comprobación de la operación +, -
void tsOpSign(entradaTS op, entradaTS o, entradaTS* res){

    if ((o.tipoDato != real && o.tipoDato != entero) || isList(o)) {
		printf("Semantic Error(%d): Operator expects integer or real expression.", yylineno);
	}

	res->tipoDato = o.tipoDato;
	res->dimensiones = 0;
}


// Realiza la comprobación de la operación +, - binaria
void tsOpSignBin(entradaTS o1, entradaTS op, entradaTS o2, entradaTS* res){

    if (o1.tipoDato != o2.tipoDato) {
	    printf("Semantic Error(%d): Expressions must be equals types.", yylineno);
  		return;
  	}

	if (o1.tipoDato != entero && o1.tipoDato != real) {
		printf("Semantic Error%d): Invalid type in op. Both must be equals.", yylineno);
		return;
	}

	if (isList(o1) && isList(o2)){

		if(equalSize(o1,o2)){

			res->tipoDato = o1.tipoDato;
			res->dimensiones = o1.dimensiones;


		} else {

            printf("Semantic Error(%d): Size arrays must be same", yylineno);
			return;

		}

	} else {

		if (isList(o1) && !isList(o2)) {

			res->tipoDato = o1.tipoDato;
			res->dimensiones= o1.dimensiones;


		}

		if (!isList(o1) && isList(o2)){

			if (strcmp(op.nombre,"-")==0){

				printf("Semantic Error(%d): Operation not allowed.", yylineno);
				return;

			} else {

				res->tipoDato = o2.tipoDato;
				res->dimensiones= o2.dimensiones;


			}

		}

	}

}

// Realiza la comprobación de la operación *, /

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

		}
        else{
            res->tipoDato = o2.tipoDato;
			res->dimensiones = o2.dimensiones;
        }
	}

}

// Realiza la comprobación de la operación &&

void tsOpAnd(entradaTS o1, entradaTS op, entradaTS o2, entradaTS* res){

    if (o1.tipoDato != o2.tipoDato) {
		printf("Semantic Error (%d): Expressions must be same types.", yylineno);
		return;
	}
	if (o1.tipoDato != booleano || isList(o1) || isList(o2)) {
		printf("Semantic Error(%d):Invalid type in op. Both must be same. Expects BOOLEANO", yylineno);
		return;
	}

	res->tipoDato = booleano;
	res->dimensiones = 0;


}

// Realiza la comprobación de la operación ||

void tsOpOr(entradaTS o1, entradaTS op, entradaTS o2, entradaTS* res){

    if (o1.tipoDato != o2.tipoDato) {
		printf("Semantic Error (%d): Expressions must be same types.", yylineno);
		return;
	}
	if (o1.tipoDato != booleano || isList(o1) || isList(o2)) {
		printf("Semantic Error(%d):Invalid type in op. Both must be same. Expects booleano", yylineno);
		return;
	}

	res->tipoDato = booleano;
	res->dimensiones = 0;
}

// Realiza la comprobación de la operación ==, !=

void tsOpEqual(entradaTS o1, entradaTS op, entradaTS o2, entradaTS* res){

    if (o1.tipoDato != o2.tipoDato) {
		printf("Semantic Error (%d): Expressions must be same types.", yylineno);
		return;
	}
	if (isList(o1) || isList(o2)) {
		printf("Semantic Error(%d):Invalid type in op. Both must be same. Expects ENTERO or REAL.", yylineno);
		return;
	}

	res->tipoDato = booleano;
	res->dimensiones = 0;
}


// Realiza la comprobación de la operación <, >, <=, >=, <>
void tsOpRel(entradaTS o1, entradaTS op, entradaTS o2, entradaTS* res){

    if (o1.tipoDato != o2.tipoDato) {

		printf("Semantic Error (%d): Expressions must be same types.", yylineno);
		return;
	}
	if ((o1.tipoDato != entero && o1.tipoDato != real) || isList(o1) || isList(o2)) {
		printf("Semantic Error(%d):Invalid type in op. Both must be same. Expects ENTERO or REAL.", yylineno);
		return;
	}

	res->tipoDato = booleano;
	res->dimensiones = 0;

}