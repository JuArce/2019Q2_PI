#include <stdio.h>

#define MAX 100
#define TRUE 1
#define FALSE 0

int interseccion(const int vec1[], int dim1, const int vec2[], int dim2, int vec3[]);

int 
main()
{
	int v1[] = {1,15,2,23,33,32,12,45,67,87};
	int v2[] = {12,2,45,76,11,15,3,87,21,1};
	int v3[MAX];
	int dim3 = interseccion(v1, 10, v2, 10, v3);

	for(int i = 0; i < dim3; i++)
	{
		printf("%d\t", v3[i]);
	}
	putchar('\n');
	return 0;
}

int
interseccion(const int vec1[], int dim1, const int vec2[], int dim2, int vec3[])
{
	int i, j, k = 0;

	for(i = 0; i < dim1; i++)
	{
		for(j = 0; j < dim2; j++)
		{
			if(vec1[i] == vec2[j])
			{
				vec3[k++] = vec1[i];
			}
		}
	}

	return k;
}