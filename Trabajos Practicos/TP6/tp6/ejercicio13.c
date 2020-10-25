#include <stdio.h>

#define MAXDIM 5

void productoMatrices(int matriz1[][MAXDIM], int matriz2[][MAXDIM], int matriz3[][MAXDIM], int dim);
static int auxProdMat(int matriz1[][MAXDIM], int matriz2[][MAXDIM], int dim, int i, int j);
void imprimirMatriz(int matriz[][MAXDIM], int filas, int columnas);

int
main()
{
	int matriz1[][MAXDIM] = {{1,2,3,4,5}, {2,3,4,5,6}, {3,4,5,6,7}, {4,5,6,7,8}, {5,6,7,8,9}};
	int matriz2[][MAXDIM] = {{9,8,7,6,5}, {8,7,6,5,4}, {7,6,5,4,3}, {6,5,4,3,2}, {5,4,3,2,1}};
	int matriz3[MAXDIM][MAXDIM];
	int dim = MAXDIM;
	productoMatrices(matriz1, matriz2, matriz3, dim);
	imprimirMatriz(matriz3, dim, dim);
	return 0;
}

void 
productoMatrices(int matriz1[][MAXDIM], int matriz2[][MAXDIM], int matriz3[][MAXDIM], int dim)
{
	for(int i = 0; i < dim; i++)
	{
		for(int j = 0; j < dim; j++)
		{
			matriz3[i][j] = auxProdMat(matriz1, matriz2, dim, i, j);
		}
	}

	return;
}

static int 
auxProdMat(int matriz1[][MAXDIM], int matriz2[][MAXDIM], int dim, int i, int j)
{
	int aux = 0;

	for(int r = 0; r < dim; r++)
	{
		aux += matriz1[i][r] * matriz2[r][j];
	}

	return aux;
}

void
imprimirMatriz(int matriz[][MAXDIM], int filas, int columnas)
{
	for(int i = 0; i < filas; i++)
	{
		for(int j = 0; j < columnas; j++)
		{
			printf("%d\t", matriz[i][j]);
		}
		putchar('\n');
	}
	return;
}