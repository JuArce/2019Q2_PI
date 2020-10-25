#include <stdio.h>
#include <stdlib.h>
#include "getnum.h"

#define BLOQUE 5
#define TRUE 1
#define FALSE 0

int * leerNumeros(int * dim);
static int aparece(int n, int * vector, int dim);
void imprimirVector(int * vector, int dim);

int
main()
{

	int * vector;
	int dim;
	vector = leerNumeros(&dim);
	imprimirVector(vector, dim);
	free(vector);
	return 0;
}

int *
leerNumeros(int * dim)
{
	int i = 0; 
	int *vector = NULL;
	int numero;
	int repetido = FALSE;
	do
	{
		numero = getint("Ingrese un numero\n");
		if(!aparece(numero, vector, i))
		{
			if(i % BLOQUE == 0)
			{
				vector = realloc(vector, (i + BLOQUE) * sizeof(int));
			}
			vector[i++] = numero;
		}
		else
		{
			repetido = TRUE;
		}
	}while(!repetido);

	vector = realloc(vector, i * sizeof(int));
	*dim = i;
	return vector;
}

static int
aparece(int n, int * vector, int dim)
{
	for(int i = 0; i < dim; i++)
	{
		if(n == vector[i])
		{
			return 1;
		}
	}

	return 0;
}

void
imprimirVector(int * vector, int dim)
{
	for(int i = 0; i < dim; i++)
	{
		printf("%d\t", vector[i]);
	}putchar('\n');
	return;
}