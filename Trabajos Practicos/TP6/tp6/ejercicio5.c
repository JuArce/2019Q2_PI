#include <stdio.h>

#define MAX 100
#define TRUE 1
#define FALSE 0

int eliminaRepetidos(const int vector[], int dim, int nuevoVector[]);

int
main()
{
	int v1[] = {1, 2, 2, 2, 2, 3, 4, 5, 5, 6, 7, 9, 9, 9};
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

	nuevoVector[0] = vector[0];
	nuevaDim++;

	for(int i = 1; i < dim; i++)
	{
		if(vector[i] != nuevoVector[nuevaDim - 1])
		{
			nuevoVector[nuevaDim++] = vector[i];
		}
	}

	return nuevaDim;
}

/*Otra version
int
eliminaRepetidos(const int vector[], int dim, int nuevoVector[])
{
	int nuevaDim = 0;

	nuevoVector[0] = vector[0];
	//nuevaDim++;

	for(int i = 1; i < dim; i++)
	{
		if(vector[i] != nuevoVector[nuevaDim])
		{
			nuevoVector[++nuevaDim] = vector[i];
		}
	}

	return ++nuevaDim;
}*/