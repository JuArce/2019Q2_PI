#include <stdio.h>
#include "random.h"

#define MAX 100
#define RANGO_MIN 0
#define RANGO_MAX 20
#define DIMENSION 5

void traspuesta(int matriz[][MAX], int dim);
void generarMatriz(int matriz[][MAX], int dim);
void imprimirMatriz(int matriz[][MAX], int dim);

int
main()
{
	int matriz[MAX][MAX];
	int dim = DIMENSION;
	generarMatriz(matriz, dim);
	imprimirMatriz(matriz, dim);
	traspuesta(matriz, dim);
	imprimirMatriz(matriz, dim);
	return 0;
}

void
traspuesta(int matriz[][MAX], int dim)
{
	int aux;
	for(int i = 1; i < dim; i++)
	{
		for(int j = 0; j < i; j++)
		{
			aux = matriz[i][j];
			matriz[i][j] = matriz[j][i];
			matriz[j][i] = aux;
		}
	}

	return;
}

void
generarMatriz(int matriz[][MAX], int dim)
{
	for(int i = 0; i < dim; i++)
	{
		for(int j = 0; j < dim; j++)
		{
			matriz[i][j] = randInt(RANGO_MIN, RANGO_MAX);
		}
	}
	return;
}

void 
imprimirMatriz(int matriz[][MAX], int dim)
{
	for(int i = 0; i < dim; i++)
	{
		for(int j = 0; j < dim; j++)
		{
			printf("%d\t", matriz[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');
	return;
}