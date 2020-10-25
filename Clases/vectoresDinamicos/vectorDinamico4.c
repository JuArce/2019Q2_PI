#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define BLOQUE 5

int * interseccionDinamica(int vec1[], int dim1, int vec2[], int dim2, int *dim3);

int
main()
{
	int v1[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int v2[] = {2,4,6,8,10,12,14,16,18,20};
	int dim1 = sizeof(v1) / sizeof(v1[0]);
	int dim2 = sizeof(v2) / sizeof(v2[0]);
	int * vector;
	int dim3;

	vector = interseccionDinamica(v1, dim1, v2, dim2, &dim3);

	for(int i = 0; i < dim3; i++)
	{
		printf("%d\t", vector[i]);
	}
	putchar('\n');
	return 0;
}

int *
interseccionDinamica(int vec1[], int dim1, int vec2[], int dim2, int *dim3)
{
	int i = 0, j = 0;

	int * vec3;

	*dim3 = 0;

	while(i < dim1 && j < dim2)
	{
		if(vec1[i] == vec2[j])
		{
			if((*dim3) % BLOQUE == 0)
			{
				vec3 = realloc(vec3, (*dim3 + BLOQUE) * sizeof(int));
			}
			vec3[*dim3] = vec1[i];
			i++; j++;
			(*dim3)++;
		}
		else if(vec1[i] < vec2[j])
		{
			i++;
		}
		else
		{
			j++;
		}
	}

	vec3 = realloc(vec3, *dim3 * sizeof(int));

	return vec3;
}