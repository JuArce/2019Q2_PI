#include <stdio.h>

#define MAX 100
#define TRUE 1
#define FALSE 0

int matrizEscalable(int matriz[][MAX], int filas, int columnas);

int 
main()
{
	int mat[][MAX] = {{1,1,1,1}, {1,2,1,1}, {1,1,2,2}, {1,1,2,3}};
	printf("%d\n", matrizEscalable(mat, 4, 4));
} 

int
matrizEscalable(int matriz[][MAX], int fils, int cols)
{
	int vecFilas[MAX] = {0};
	int vecColumnas[MAX] = {0};
	int escalable = TRUE;

	for(int i = 0; i < fils && escalable; i++)
	{
		for(int j = 0; j < cols && escalable; j++)
		{
			vecFilas[i] += matriz[i][j];
			vecColumnas[j] += matriz[i][j];
		}

		if(i > 0 && vecFilas[i] != vecFilas[i - 1] + 1)
		{
			escalable = FALSE;
		}
	}

	/*for(int i = 1; i < fils && escalable; i++)
	{
		if(vecFilas[i] != vecFilas[i - 1] + 1)
		{
			escalable = FALSE; //Deja de ser escalable por filas
		}
	}*/

	for(int i = 1; i < cols && escalable; i++)
	{
		if(vecColumnas[i] != vecColumnas[i - 1] + 1)
		{
			escalable = FALSE; //Deja de ser escalable por columnas
		}
	}

	return escalable;
}