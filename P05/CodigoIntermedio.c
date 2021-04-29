#include <stdio.h>
#include "dec_dat"
#include "dec_fun"
int N;
int Dato;
int contador;
int prev;
int temp;
int main()
{
	printf("%s", "Introduzca un número");
	printf("\n");
	scanf("%d", &N);
	{
		contador = 0;
	}
	{
		prev = 0;
	}
	{
		etiqueta0: ;
		int temp0;
		temp0 = N > contador;
		if (!temp0) goto etiqueta1;
		{
			{
				int temp1;
				temp1 = contador == 0;
				if (!temp1) goto etiqueta2;
				{
					{
						Dato = prev;
					}
				}
				goto etiqueta3;
				etiqueta2: 
				{
					int temp2;
					temp2 = contador == 1;
					if (!temp2) goto etiqueta4;
					{
						{
							Dato = 1;
						}
					}
					goto etiqueta5;
					etiqueta4: 
					{
						{
							temp = Dato;
						}
						{
							int temp3;
							temp3 = Dato + prev;
							Dato = temp3;
						}
						{
							prev = temp;
						}
					}
				}
				etiqueta5: ;
			}
			etiqueta3: ;
			printf("%s", "Elemento nro ");
			printf("%d", contador);
			printf("%s", ": ");
			printf("%d", Dato);
			printf("\n");
			{
				int temp4;
				temp4 = contador + 1;
				contador = temp4;
			}
		}
		goto etiqueta0;
	}
	etiqueta1: ;
	printf("%s", "Dato * 10 = ");
	int temp5;
	temp5 = Dato * 10;
	printf("%d", temp5);
	printf("\n");
	printf("%s", "Dato / ");
	int temp6;
	temp6 = N - 1;
	printf("%d", temp6);
	printf("%s", " = ");
	int temp7;
	temp7 = N - 1;
	int temp8;
	temp8 = Dato / temp7;
	printf("%d", temp8);
	printf("\n");
}
