#ifndef ANALIZADOR_SEM_NTICO_H_INCLUDED
#define ANALIZADOR_SEM_NTICO_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


typedef enum {
    entero,
    real,
    caracter,
    booleano,
    lista,
    desconocido
} dtipo;

// Define el tipo de expresiones que puede haber en el codigo.
typedef enum {
    marca,
    funcion,
    variable,
    parametro_formal
} tipoEntrada;


// Define una entrada para la tabla de simbolos
typedef struct {
    tipoEntrada     entrada;
    char*           nombre;
    dtipo           tipoDato;
    unsigned int    parametros;
    unsigned int    dimensiones;
} entradaTS ;

#define MAX_TS 500

unsigned int TOPE;
unsigned int subProg;
dtipo tipoTmp;

extern int yylineno;

entradaTS TS[MAX_TS];

// Representa las caracteristicas de una variable
typedef struct {
    int          atrib;     //
    char *       lexema;    // Expresiones de los token
    dtipo        tipo;      // Tipo de dato
} atributos;

#define YYSTYPE atributos

void TS_IncrementarTope();
void TS_InsertaMARCA();
void TS_VaciarENTRADAS();
void TS_InsertaID(YYSTYPE ident);
void TS_InsertaSUBPROG(YYSTYPE subprog);
void TS_InsertaPARAMF(YYSTYPE paramf);
YYSTYPE TS_OpBoolBin(YYSTYPE arg1, YYSTYPE arg2);
void TS_BoolCondition(YYSTYPE expr);
void TS_Imprimir();
bool isList(entradaTS e);
int equalSize(entradaTS e1, entradaTS e2);


/////////////////////SEMANTICO/////////////////////////

// Realiza la comprobación de la operación !, &, ~
void tsOpUnary(entradaTS op, entradaTS o, entradaTS* res);

// Realiza la comprobación de la operación +, -
void tsOpSign(entradaTS op, entradaTS o, entradaTS* res);

// Realiza la comprobación de la operación +, - binaria
void tsOpSignBin(entradaTS o1, entradaTS op, entradaTS o2, entradaTS* res);

// Realiza la comprobación de la operación *, /
void tsOpMul(entradaTS o1, entradaTS op, entradaTS o2, entradaTS* res);

// Realiza la comprobación de la operación &&
void tsOpAnd(entradaTS o1, entradaTS op, entradaTS o2, entradaTS* res);

// Realiza la comprobación de la operación ||
void tsOpOr(entradaTS o1, entradaTS op, entradaTS o2, entradaTS* res);

// Realiza la comprobación de la operación ==, !=
void tsOpEqual(entradaTS o1, entradaTS op, entradaTS o2, entradaTS* res);

// Realiza la comprobación de la operación <, >, <=, >=, <>
void tsOpRel(entradaTS o1, entradaTS op, entradaTS o2, entradaTS* res);
#endif