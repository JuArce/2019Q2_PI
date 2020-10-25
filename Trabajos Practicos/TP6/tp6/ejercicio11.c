#include <stdio.h>

#define MAX 100

void ordenaColumna(int matriz[][MAX], int filas, int columnas, int col);
void swapFila(int fila1[], int fila2[], int dim);
void imprimirMatriz(int matriz[][MAX], int filas, int columnas);

int 
main()
{
	int matriz[][MAX] = {{1,2,3,4,5},
					  {6,7,8,9,10},
					  {3,5,8,2,1},
					  {8,1,3,6,7}};
	int filas = 4;
	int columnas = 5;

	imprimirMatriz(matriz, filas, columnas);

	for(int i = 1; i <=5; i++)
	{
		ordenaColumna(matriz, filas, columnas, i);	
		imprimirMatriz(matriz, filas, columnas);
	}




	return 0;
}

void
ordenaColumna(int matriz[][MAX], int filas, int columnas, int col)
{
	col--; /*Como el usuario indica las columnas a partir del 1, le
		   ** restamos uno para que coincida con la forma normal de 
		   **recorrer arreglos, que es empezando por cero
		   */

	for(int i = 0; i < filas - 1; i++)
	{
		for(int j = i + 1; j < filas; j++)
		{
			if(matriz[i][col] > matriz[j][col])
			{
				swapFila(matriz[i], matriz[j], columnas);
			}
		}
	}

	return;
}

void
swapFila(int fila1[], int fila2[], int dim)
{
	int aux;
	for(int i = 0; i < dim; i++)
	{
		aux = fila1[i];
		fila1[i] = fila2[i];
		fila2[i] = aux;
	}
	return;
}

void 
imprimirMatriz(int matriz[][MAX], int filas, int columnas)
{
	for(int i = 0; i < filas; i++)
	{
		for(int j = 0; j < columnas; j++)
		{
			printf("%d\t", matriz[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');
	return;
}