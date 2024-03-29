#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dec_dat.c"

////////////////////////////////////////////////////////////////////////////
////////////////////////      ENTEROS      /////////////////////////////////
////////////////////////////////////////////////////////////////////////////

//struct listOfInt *actual = NULL;

void printListInt(struct listOfInt * lista) {
   struct listOfInt *ptr = lista;
   printf("\n[ ");
	
   //empezamos por el principio
   while(ptr != NULL) {
      printf("%d",ptr->data);
      ptr = ptr->next;
   }
   printf(" ]");
}

void insertFirstInt(int data) {
   //creamos un link
   struct listOfInt *link = (struct listOfInt*) malloc(sizeof(struct listOfInt));
	
   link->data = data;
	
   //lo apuntamos al anterior ListOfInt
   link->next = primero;
	
   //apuntamos primero al nuevo primer nodo
   primero = link;
}

struct listOfInt* insertIntElement(struct listOfInt* lista, int indice , int data){
    struct listOfInt * nuevo;
    nuevo->data = data;
    struct listOfInt * actual = lista;
    int pos = 0;
    while (pos < indice-1){
        actual = actual->next;
        ++pos;
    }
    nuevo->next = actual->next;
    actual->next = nuevo;
    return lista;
}

struct listOfInt * concatenarListasInt(struct listOfInt * unaLista , struct listOfInt * otralista){
    struct listOfInt * actual;
    if (unaLista == NULL){ 
        unaLista = otralista;
    }
    else{
        if (otralista != NULL){  
            actual = unaLista;           
            while (actual->next != NULL)
                actual = actual->next;
            actual->next = otralista;        
        }
    }
    return unaLista;  
}

int GCI_BusquedaPorIndice(struct listOfInt * lista, int indice) {
    struct listOfInt * nuevo;
    struct listOfInt * actual = lista;
    for (int i=0; i<indice;i++) {
        actual = actual->next;
    }
    return actual->data;
}

//eliminamos el primer item
struct listOfInt* deleteFirstInt() {

   //guardamos la referencia a la primera posición
   struct listOfInt *tempLink = primero;
	
   //ponemos el segundo como si fuese el primero 
   primero = primero->next;
	
   //devolvemos el elemento borrado
   return tempLink;
}

bool isEmptyInt() {
   return primero == NULL;
}

int lengthInt() {
   int tam = 0;
   struct listOfInt *actual;
	
   for(actual = primero; actual != NULL; actual = actual->next) {
      tam++;
   }
	
   return tam;
}

struct listOfInt* findInt(int dato) {

   //comenzamos por el principio
   struct listOfInt* actual = primero;

   //si la lista está vacía
   if(primero == NULL) {
      return NULL;
   }

   //navegamos por la lista
   while(actual->data != dato) {
	
      //si es el último listOfInt
      if(actual->next == NULL) {
         return NULL;
      } else {
         //si no ir al siguiente elemento de la lista
         actual = actual->next;
      }
   }      
	
   
   return actual;
}

struct listOfInt* deleteInt(int dato) {

   //comenzamos por el inicio
   struct listOfInt* actual = primero;
   struct listOfInt* previous = NULL;
	
   //si la lista está vacía
   if(primero == NULL) {
      return NULL;
   }

   //navegamos por la lista
   while(actual->data != dato) {

      //si es el último listOfInt
      if(actual->next == NULL) {
         return NULL;
      } else {
         //guardamos la referencia al elemento actual
         previous = actual;
         //move to next link
         actual = actual->next;
      }
   }

   //si lo encontramos 
   if(actual == primero) {
      //movemos la lista para eliminarlo
      primero = primero->next;
   } else {
      
      previous->next = actual->next;
   }    
	
   return actual;
}

void sortInt() {

   int i, j, k, datoTemporal;
   struct listOfInt *actual;
   struct listOfInt *next;
	
   int size = length();
   k = size ;
	
   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      actual = primero;
      next = primero->next;
		
      for ( j = 1 ; j < k ; j++ ) {   

         if ( actual->data > next->data ) {
            datoTemporal = actual->data;
            actual->data = next->data;
            next->data = datoTemporal;
         }
			
         actual = actual->next;
         next = next->next;
      }
   }   
}








////////////////////////////////////////////////////////////////////////////
////////////////////////      CHAR      /////////////////////////////////
////////////////////////////////////////////////////////////////////////////









struct listOfChar *primeroC = NULL;
struct listOfChar *actualCC = NULL;

void printListChar() {
   struct listOfChar *ptr = primeroC;
   printf("\n[ ");
	
   //empezamos por el principio
   while(ptr != NULL) {
      printf("%s",ptr->data);
      ptr = ptr->next;
   }
   printf(" ]");
}

void insertFirstChar(char data) {
   //creamos un link
   struct listOfChar *link = (struct listOfChar*) malloc(sizeof(struct listOfChar));
	
   link->data = data;
	
   //lo apuntamos al anterior listOfChar
   link->next = primeroC;
	
   //apuntamos primero al nuevo primer nodo
   primeroC = link;
}


//eliminamos el primer item
struct listOfChar* deleteFirstChar() {

   //guardamos la referencia a la primera posición
   struct listOfChar *tempLink = primeroC;
	
   //ponemos el segundo como si fuese el primero 
   primeroC = primeroC->next;
	
   //devolvemos el elemento borrado
   return tempLink;
}

bool isEmptyChar() {
   return primeroC == NULL;
}

int lengthChar() {
   int tam = 0;
   struct listOfChar *actualC;
	
   for(actualC = primeroC; actualC != NULL; actualC = actualC->next) {
      tam++;
   }
	
   return tam;
}

struct listOfChar* findChar(char dato) {

   //comenzamos por el principio
   struct listOfChar* actualC = primeroC;

   //si la lista está vacía
   if(primeroC == NULL) {
      return NULL;
   }

   //navegamos por la lista
   while(actualC->data != dato) {
	
      //si es el último listOfChar
      if(actualC->next == NULL) {
         return NULL;
      } else {
         //si no ir al siguiente elemento de la lista
         actualC = actualC->next;
      }
   }      
	

   return actualC;
}

struct listOfChar* deleteChar(char dato) {

   //comenzamos por el inicio
   struct listOfChar* actualC = primeroC;
   struct listOfChar* previous = NULL;
	
   //si la lista está vacía
   if(primeroC == NULL) {
      return NULL;
   }

   //navegamos por la lista
   while(actualC->data != dato) {

      //si es el último listOfChar
      if(actualC->next == NULL) {
         return NULL;
      } else {
         //guardamos la referencia al elemento actualC
         previous = actualC;
         //move to next link
         actualC = actualC->next;
      }
   }

   //si lo encontramos 
   if(actualC == primeroC) {
      //movemos la lista para eliminarlo
      primeroC = primeroC->next;
   } else {
      
      previous->next = actualC->next;
   }    
	
   return actualC;
}















////////////////////////////////////////////////////////////////////////////
////////////////////////      BOOLEANOS      /////////////////////////////////
////////////////////////////////////////////////////////////////////////////



struct listOfBool *primeroB = NULL;
struct listOfBool *actualB = NULL;

void printListBool() {
   struct listOfBool *ptr = primeroB;
   printf("\n[ ");
	
   //empezamos por el principio
   while(ptr != NULL) {
      printf("%d",ptr->data);
      ptr = ptr->next;
   }
   printf(" ]");
}

void insertFirstBool(bool data) {
   //creamos un link
   struct listOfBool *link = (struct listOfBool*) malloc(sizeof(struct listOfBool));
	
   link->data = data;
	
   //lo apuntamos al anterior listOfBool
   link->next = primeroB;
	
   //apuntamos primero al nuevo primer nodo
   primeroB = link;
}


//eliminamos el primer item
struct listOfBool* deleteFirstBool() {

   //guardamos la referencia a la primera posición
   struct listOfBool *tempLink = primeroB;
	
   //ponemos el segundo como si fuese el primero 
   primeroB = primeroB->next;
	
   //devolvemos el elemento borrado
   return tempLink;
}

bool isEmptyBool() {
   return primeroB == NULL;
}

int lengthBool() {
   int tam = 0;
   struct listOfBool *actualB;
	
   for(actualB = primeroB; actualB != NULL; actualB = actualB->next) {
      tam++;
   }
	
   return tam;
}

/* //AUNQUE NO TENGA MUCHO SENTIDO LO DEJO COMENTADO
struct listOfBool* findBool(bool dato) {

   //comenzamos por el principio
   struct listOfBool* actualB = primeroB;

   //si la lista está vacía
   if(primeroB == NULL) {
      return NULL;
   }

   //navegamos por la lista
   while(actualB->data != dato) {
	
      //si es el último listOfBool
      if(actualB->next == NULL) {
         return NULL;
      } else {
         //si no ir al siguiente elemento de la lista
         actualB = actualB->next;
      }
   }      
	
  
   return actualB;
}

struct listOfBool* deleteBool(bool dato) {

   //comenzamos por el inicio
   struct listOfBool* actualB = primeroB;
   struct listOfBool* previous = NULL;
	
   //si la lista está vacía
   if(primeroB == NULL) {
      return NULL;
   }

   //navegamos por la lista
   while(actualB->data != dato) {

      //si es el último listOfBool
      if(actualB->next == NULL) {
         return NULL;
      } else {
         //guardamos la referencia al elemento actual
         previous = actualB;
         //move to next link
         actualB = actualB->next;
      }
   }

   //si lo encontramos 
   if(actualB == primeroB) {
      //movemos la lista para eliminarlo
      primeroB = primeroB->next;
   } else {
      
      previous->next = actualB->next;
   }    
	
   return actualB;
}
*/









////////////////////////////////////////////////////////////////////////////
////////////////////////      FLOTANTES      /////////////////////////////////
////////////////////////////////////////////////////////////////////////////

struct listOfFloat *primeroF = NULL;
struct listOfFloat *actualFF = NULL;

void printListFloat() {
   struct listOfFloat *ptr = primeroF;
   printf("\n[ ");
	
   //empezamos por el principio
   while(ptr != NULL) {
      printf("%f",ptr->data);
      ptr = ptr->next;
   }
   printf(" ]");
}

void insertFirstFloat(int data) {
   //creamos un link
   struct listOfFloat *link = (struct listOfFloat*) malloc(sizeof(struct listOfFloat));
	
   link->data = data;
	
   //lo apuntamos al anterior listOfFloat
   link->next = primeroF;
	
   //apuntamos primero al nuevo primer nodo
   primeroF = link;
}


//eliminamos el primer item
struct listOfFloat* deleteFirstFloat() {

   //guardamos la referencia a la primera posición
   struct listOfFloat *tempLink = primeroF;
	
   //ponemos el segundo como si fuese el primero 
   primeroF = primeroF->next;
	
   //devolvemos el elemento borrado
   return tempLink;
}

bool isEmpty() {
   return primeroF == NULL;
}

int length() {
   int tam = 0;
   struct listOfFloat *actualF;
	
   for(actualF = primeroF; actualF != NULL; actualF = actualFF->next) {
      tam++;
   }
	
   return tam;
}

struct listOfFloat* findFloat(int dato) {

   //comenzamos por el principio
   struct listOfFloat* actualF = primeroF;

   //si la lista está vacía
   if(primeroF == NULL) {
      return NULL;
   }

   //navegamos por la lista
   while(actualF->data != dato) {
	
      //si es el último listOfFloat
      if(actualF->next == NULL) {
         return NULL;
      } else {
         //si no ir al siguiente elemento de la lista
         actualF = actualF->next;
      }
   }      
	
   
   return actualF;
}

struct listOfFloat* deleteFloat(int dato) {

   //comenzamos por el inicio
   struct listOfFloat* actualF = primeroF;
   struct listOfFloat* previous = NULL;
	
   //si la lista está vacía
   if(primeroF == NULL) {
      return NULL;
   }

   //navegamos por la lista
   while(actualF->data != dato) {

      //si es el último listOfFloat
      if(actualF->next == NULL) {
         return NULL;
      } else {
         //guardamos la referencia al elemento actual
         previous = actualF;
         //move to next link
         actualF = actualF->next;
      }
   }

   //si lo encontramos 
   if(actualF == primeroF) {
      //movemos la lista para eliminarlo
      primeroF = primeroF->next;
   } else {
      
      previous->next = actualF->next;
   }    
	
   return actualF;
}

void sortFloat() {

   int i, j, k, datoTemporal;
   struct listOfFloat *actualF;
   struct listOfFloat *next;
	
   int size = length();
   k = size ;
	
   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      actualF = primeroF;
      next = primeroF->next;
		
      for ( j = 1 ; j < k ; j++ ) {   

         if ( actualF->data > next->data ) {
            datoTemporal = actualF->data;
            actualF->data = next->data;
            next->data = datoTemporal;
         }
			
         actualF = actualF->next;
         next = next->next;
      }
   }   
}