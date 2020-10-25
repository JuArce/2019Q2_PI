#include <stdio.h>

#define MAX 100
#define TRUE 1
#define FALSE 0

int eliminaRepetidos(const int vector[], int dim, int nuevoVector[]);

int
main()
{
	int v1[] = {1, 2, 2, 3, 2, 2, 3, 4, 5, 1, 9, 3, 5, 6, 7, 3, 4, 5, 6};
	int dim1 = sizeof(v1) / sizeof(v1[0]);
	int v2[MAX];
	int dim2 = eliminaRepetidos(v1, dim1, v2);

	for(int i = 0; i < dim1; i++)
	{
		printf("%d\t", v1[i]);
	}
	putchar('\n');
	putchar('\n');

	for(int i = 0; i < dim2; i++)
	{
		printf("%d\t", v2[i]);
	}
	putchar('\n');
}

int
eliminaRepetidos(const int vector[], int dim, int nuevoVector[])
{
	int nuevaDim = 0;
	int yaExiste = FALSE;
	printf("%d\n", dim);
	for(int i = 0; i < dim; i++)
	{
		yaExiste = FALSE;
		for(int j = 0; j < nuevaDim && !yaExiste; j++)
		{
			if(vector[i] == nuevoVector[j])
			{
				yaExiste = TRUE;
			}
		}
		if(!yaExiste)
		{
			nuevoVector[nuevaDim++] = vector[i];
		}
	}
	return nuevaDim;
}