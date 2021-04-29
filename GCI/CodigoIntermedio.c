#include <stdio.h>
#include "dec_dat"
#include "dec_fun"
int N;
struct listOfInt * Dato1;
struct listOfInt * Dato2;
struct listOfInt * Dato3;
int contador;
int main()
{
	printf("%s", "Introduzca un número");
	printf("\n");
	scanf("%d", &N);
	{
		contador = 0;
	}
	{
		etiqueta0: ;
		int temp0;
		temp0 = N > contador;
		if (!temp0) goto etiqueta1;
		{
			{
				int temp1;
				temp1 = contador < 2;
				if (!temp1) goto etiqueta2;
				{
					{
						struct listOfInt * temp2 = (struct listOfInt*) malloc(sizeof(struct listOfInt));
						temp2 = insertIntElement(Dato1, contador, contador);
						Dato1 = temp2;
					}
				}
				goto etiqueta3;
				etiqueta2: 
				{
					{
						int temp3;
						temp3 = contador - 1;
						int temp4;
						temp4 = GCI_BusquedaPorIndice(Dato1, temp3);
						int temp5;
						temp5 = contador - 2;
						int temp6;
						temp6 = GCI_BusquedaPorIndice(Dato1, temp5);
						int temp7;
						temp7 = temp4 + temp6;
						struct listOfInt * temp8 = (struct listOfInt*) malloc(sizeof(struct listOfInt));
						temp8 = insertIntElement(Dato1, temp7, contador);
						Dato1 = temp8;
					}
				}
			}
			etiqueta3: ;
			{
				int temp9;
				temp9 = contador + 1;
				contador = temp9;
			}
		}
		goto etiqueta0;
	}
	etiqueta1: ;
	printListInt(Dato1);
	printf("\n");
	{
		struct listOfInt * temp10 = (struct listOfInt*) malloc(sizeof(struct listOfInt));
		temp10 = GCI_Multiplica(Dato1, 2);
		Dato2 = temp10;
	}
	printListInt(Dato2);
	printf("\n");
	{
		struct listOfInt * temp11 = (struct listOfInt*) malloc(sizeof(struct listOfInt));
		temp11 = concatenarListasInt(Dato1, Dato2);
		int temp12;
		temp12 = N - 1;
		struct listOfInt * temp13 = (struct listOfInt*) malloc(sizeof(struct listOfInt));
		temp13 = GCI_Multiplica(temp11, temp12);
		Dato3 = temp13;
	}
	printListInt(Dato3);
	printf("\n");
}
