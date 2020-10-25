#include <stdio.h>
#include "random.h"

#define MAX 20

void desordenar(int vector[], int dim);

int
main()
{
	randomize();
	int vec[MAX];
	for(int i = 0; i < MAX; i++)
	{
		vec[i] = i + 1;
	}

	for(int i = 0; i < MAX; i++)
	{
		printf("%d\t", vec[i]);
	}
	putchar('\n');
	putchar('\n');

	desordenar(vec, MAX);

	for(int i = 0; i < MAX; i++)
	{
		printf("%d\t", vec[i]);
	}
	putchar('\n');
}

void
desordenar(int vector[], int dim)
{
	int random, aux;

	for(int i = 0; i < dim; i++)
	{
		random = randInt(0, dim-1);
		aux = vector[i];
		vector[i] = vector[random];
		vector[random] = aux;
	}

	return;
}