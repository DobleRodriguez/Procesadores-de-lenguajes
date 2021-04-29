#include "semantic.h"
#include <stdbool.h>


long int LIMIT = 0;

int LINE = 1;

type_data globalType ;

bool DEC_VAR = false; // True si se esta declarando una varaible

input list_of_inputs[MAX_SIZE];

int subProg = 0;

int number_of_parameters = 0;
int currentFunction = -1;

// Comprueba si el atributo es un array
// Este probablemente haya que quitarlo porque usamos listas, no arrays
inline int check_array(attributes e){
    return (e.dimensions != 0);
} 


// Comprueba si dos listas tienen el mismo tama�o
// Este probablemente haya que quitarlo porque usamos listas, no arrays
int check_lists_size(attributes e1, attributes e2){
    int respuesta = 0;
    if (e1.dimensions == e2.dimensions)
        respuesta = 1;
    return respuesta;
}

// Guarda el tipo de dato de una variable
int get_type(attributes variable){
    globalType = variable.type;
}

// añade un simbolo a la tabla de simbolos
void put_symbol(input e){
    // Devuelve 1 si consige introducir el simbolo
    if (LIMIT < MAX_SIZE) {
        list_of_inputs[LIMIT].exp = e.exp;
        list_of_inputs[LIMIT].lexema = e.lexema;
        list_of_inputs[LIMIT].type = e.type;
        list_of_inputs[LIMIT].number_of_parameters = e.number_of_parameters;
        list_of_inputs[LIMIT].dimensions = e.dimensions;
        LIMIT++;
    } else {
        printf("Semantic error (%d): Stack overflow", LINE);
    }
}

// Reduce el limite de la tabla de simbolos
int delete_symbol(){
    if (LIMIT > 0) {
        LIMIT--;
        return 1;
    } else {
        printf("Semantic error (%d): Empty table", LINE);
        return 0;
    }
}

// Elimina las inputs de la tabla de simbolos hasta que encuentre un break
void clean_table(){
    while (list_of_inputs[LIMIT - 1].exp != BREAK && LIMIT > 0) {
        LIMIT--;
    }
    if (list_of_inputs[LIMIT - 1].exp == BREAK) {
        LIMIT--;
    }
}

/*
 *
 * Busca un lexema por id
 *
 * Devuelve la poscion en la que se encuentra un lexema.
 *
 * Si no lo encuentra devuelve -1
 *
 */
int find_lex_id(attributes e){
    int pos = LIMIT - 1;
    bool encontrado = false;
    while (!encontrado && pos >= 0) {
        if (list_of_inputs[pos].exp == FUNCTION && strcmp(e.lexema, list_of_inputs[pos].lexema) == 0) {
            encontrado = true;
        } else {
            pos--;
        }
    }
    if (encontrado) {
        return pos;
    } else {
        return -1;
    }
}

/*
 *
 * Busca un lexema por nombre
 *
 * Devuelve la poscion en la que se encuentra un lexema.
 *
 * Si no lo encuentra devuelve -1
 *
 */
int find_lex_name(attributes e){
    int pos = LIMIT - 1;
    bool encontrado = false;
    while (!encontrado && pos > 0) {
        if (list_of_inputs[pos].lexema == FUNCTION && strcmp(e.lexema, list_of_inputs[pos].lexema) == 0) {
            encontrado = true;
        } else {
            pos--;
        }
        if (encontrado) {
            return pos;
        } else {
            return -1;
        }
    }
}

// Aniadir varaible
void add_variable(attributes e){
    int pos = LIMIT - 1;
    bool encontrado = false;
    while (!encontrado && pos != currentFunction) {
        if (strcmp(list_of_inputs[pos].lexema, e.lexema) != 0) {
            pos--;
        } else {
            encontrado = true;
            printf("Ya existe una variable con ese nombre. Linea %d  Variable: %s", LINE, e.lexema);
        }
    }


    // Si no existe la variable, la introducimos
    if (!encontrado) {
        input nueva;
        nueva.exp = VARIABLE;
        nueva.lexema = e.lexema;
        nueva.type = globalType;
        nueva.number_of_parameters = 0;
        nueva.dimensions = e.dimensions;
    }
}

//Introduce un break en el tope
void add_break(){
	input aux;    
    aux.exp = BREAK;	
    aux.lexema = "{";	
    aux.type = NOT_ASIGNED;
	aux.number_of_parameters = 0;
    aux.dimensions = 0;
    put_symbol(aux);
    if(subProg == 1){
        int pos = LIMIT - 2; 
        int mark = 0;
        int function = 0;
        while(pos > 0 && list_of_inputs[pos].exp == PROCEDURE){
            if(list_of_inputs[pos].exp == PROCEDURE){
                input aux2;
                aux2.exp = VARIABLE;
                aux2.dimensions = list_of_inputs[pos].dimensions;
                aux2.lexema = list_of_inputs[pos].lexema;
                aux2.number_of_parameters = list_of_inputs[pos].number_of_parameters;
                aux2.type = list_of_inputs[pos].type;
                put_symbol(aux2);
            }
            pos--;
        }
    }
}

//Introduce una entrada de subprograma

void add_subprograma(attributes a){
	input subprograma;
	subprograma.dimensions = 0;
	subprograma.exp = FUNCTION;
	subprograma.number_of_parameters = 0;
	subprograma.lexema = a.lexema;
	subprograma.type = a.type;
	currentFunction = LIMIT;
	put_symbol(subprograma);
}



void add_parameter(attributes a){
	int pos = LIMIT -1; 
	bool encontrado = false;
	while((pos != currentFunction) && !encontrado){
		if(strcmp(list_of_inputs[pos].lexema , a.lexema) != 0){	
			pos--;	
		}else{
			encontrado = true;
			printf("Error en la linea %d.Existe Parametro: %s \n",line,a.lexema);			
		}
	}
	
	if(!encontrado){
		input nueva;
		nueva.dimensions = a.dimensions;
		nueva.exp = PROCEDURE;
		nueva.lexema = a.lexema;
		nueva.number_of_parameters = 0;
		nueva.type = globalType;
		put_symbol(nueva);
	}
}

void updateNparam(attributes e){
    list_of_inputs[currentFunction].number_of_parameters = number_of_parameters;
	list_of_inputs[currentFunction].dimensions=e.dimensions;
}