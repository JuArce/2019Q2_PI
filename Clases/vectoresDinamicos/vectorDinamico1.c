#include <stdio.h>
#include <stdlib.h>
#include "getnum.h"

float * generarVector(int * dim);
void imprimirVector(float * vector, int dim);

int
main()
{
	float * vec;
	int dim;
	vec = generarVector(&dim);
	imprimirVector(vec, dim);
	free(vec);
	return 0;
}

float * 
generarVector(int * dim)
{
	do
	{
		*dim = getint("Ingrese cantidad de elementos\n");
	}while(*dim <= 0);
	
	float * vector = malloc(*dim * sizeof(float));

	for(int i = 0; i < *dim; i++)
	{
		*(vector + i) = getfloat("Ingrese un numero\n");
	}

	return vector;
}

void 
imprimirVector(float * vector, int dim)
{
	for(int i = 0; i < dim; i++)
	{
		printf("%g\t", *(vector + i));
	}
	putchar('\n');

	return;
}
