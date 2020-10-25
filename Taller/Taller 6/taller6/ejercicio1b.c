//Union de dos vectores ordenados

#include <stdio.h>

#define MAX 100
#define TRUE 1
#define FALSE 0

int unionVectores(const int vec1[], int dim1, const int vec2[], int dim2, int vec3[]);

int 
main()
{
	int v1[] = {1,2,8,12,15,25,46,89};
	int v2[] = {1,2,3,4,5,6,46};
	int v3[MAX];
	int dim3 = unionVectores(v1, 8, v2, 7, v3);

	for(int i = 0; i < dim3; i++)
	{
		printf("%d\t", v3[i]);
	}
	putchar('\n');

	return 0;
}

int
unionVectores(const int vec1[], int dim1, const int vec2[], int dim2, int vec3[])
{
	int i = 0, j = 0, k = 0;

	while(i < dim1 && j < dim2 && k < MAX - 1)
	{
		if(vec1[i] == vec2[j])
		{
			vec3[k++] = vec1[i];
			i++; j++;
		}
		else if(vec1[i] < vec2[j])
		{
			vec3[k++] = vec1[i++];
		}
		else if(vec1[i] > vec2[j])
		{
			vec3[k++] = vec2[j++];
		}
	}

	while(i < dim1 && k < MAX - 1)
	{
		vec3[k++] = vec1[i++];
	}

	while(j < dim2 && k < MAX - 1)
	{
		vec3[k++] = vec2[j++];
	}

	return k;
}