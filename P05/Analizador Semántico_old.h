#ifndef ANALIZADOR_SEM_NTICO_H_INCLUDED
#define ANALIZADOR_SEM_NTICO_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef enum {
    entero,
    real,
    caracter,
    booleano,
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
    int             longitud;
} entradaTS ;

#define MAX_TS 500

unsigned int TOPE;
unsigned int subProg;
dtipo tipoTmp;
int list;
int nparams;

extern int yylineno;

entradaTS TS[MAX_TS];

// Representa las caracteristicas de una variable
typedef struct {
    int          atrib;     //
    char *       lexema;    // Expresiones de los token
    dtipo        tipo;      // Tipo de dato
    int          longitud;
} atributos;


#define YYSTYPE atributos

YYSTYPE func;

void TS_IncrementarTope();
void TS_InsertaMARCA();
void TS_VaciarENTRADAS();
void TS_InsertaID(YYSTYPE ident);
void TS_InsertaSUBPROG(YYSTYPE subprog);
void TS_InsertaPARAMF(YYSTYPE paramf);
YYSTYPE TS_BuscarID(YYSTYPE arg);
void TS_MismoTipo(YYSTYPE arg1, YYSTYPE arg2);
void TS_CheckBooleano(YYSTYPE arg);
YYSTYPE TS_TipoRetorno(YYSTYPE arg);
YYSTYPE TS_AsignarBoolUnario(YYSTYPE arg);
YYSTYPE TS_AsignarBoolBinario(YYSTYPE arg1, YYSTYPE op, YYSTYPE arg2);
YYSTYPE TS_AsignarNumUnario(YYSTYPE op, YYSTYPE arg);
YYSTYPE TS_AsignarNumBinario(YYSTYPE arg1, YYSTYPE op, YYSTYPE arg2);
YYSTYPE TS_AsignarComp(YYSTYPE arg1, YYSTYPE op, YYSTYPE arg2);
YYSTYPE TS_AsignarListUnario(YYSTYPE op, YYSTYPE arg);
YYSTYPE TS_AsignarListBinario(YYSTYPE arg1, YYSTYPE op, YYSTYPE arg2);
YYSTYPE TS_AsignarListTernario(YYSTYPE arg1, YYSTYPE arg2, YYSTYPE arg3);
void TS_CheckLista(YYSTYPE arg);
void TS_CheckParam(YYSTYPE arg);
YYSTYPE TS_CheckFunc(YYSTYPE arg);

void GCI_GeneraFichero();
void GCI_CerrarFichero();
void GCI_Cabecera(int subProg);
void GCI_FinBloque();

YYSTYPE TS_OpBoolBin(YYSTYPE arg1, YYSTYPE arg2);
YYSTYPE TS_OpNumBin(YYSTYPE arg1, YYSTYPE arg2);
YYSTYPE TS_OpNumUnary(YYSTYPE arg);
YYSTYPE TS_OpBoolUnary(YYSTYPE arg);
YYSTYPE TS_OpComp(YYSTYPE arg1, YYSTYPE arg2);
void TS_BoolCondition(YYSTYPE expr);
void TS_TypeCondition(YYSTYPE lhs, YYSTYPE rhs);
void TS_Imprimir();


#endif