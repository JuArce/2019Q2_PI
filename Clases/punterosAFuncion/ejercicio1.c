#include <stdio.h>
#include <stdlib.h>

#define BLOQUE 5

int * pares(int * conjunto, size_t dim, size_t * nuevaDim);

int
main()
{
	int vector[] = {1,2,3,4,5,6,7,8,9,10};
	size_t dim = 10;
	size_t nDim;
	int * v = pares(vector, dim, &nDim);
	
	for(int i = 0; i < nDim; i++)
	{
		printf("%d\t", v[i]);
	}putchar('\n');
}

int * 
pares(int * conjunto, size_t dim, size_t * nuevaDim)
{
	int * nuevoVector = NULL;
	*nuevaDim = 0;

	for(int i = 0; i < dim; i++)
	{
		if(conjunto[i] % 2 == 0)
		{
			if(*nuevaDim % BLOQUE == 0)
			{
				nuevoVector = realloc(nuevoVector, (*nuevaDim + BLOQUE) * sizeof(int));
			}
			nuevoVector[*nuevaDim] = conjunto[i];
			(*nuevaDim)++;
		}
	}

	nuevoVector = realloc(nuevoVector, (*nuevaDim) * sizeof(int));
	return nuevoVector;
}