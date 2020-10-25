//Union de dos vectores no ordenados

#include <stdio.h>

#define MAX 100
#define TRUE 1
#define FALSE 0

int unionVectores(const int vec1[], int dim1, const int vec2[], int dim2, int vec3[]);
int aparece(const int vector[], int dim, int elem);

int 
main()
{
	int v1[] = {1,12,2,23,4,8,15,31};
	int v2[] = {1,3,2,23,45,65,31};
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
	int i, j, k = 0;

	for(i = 0; i < dim1; i++)
	{
		vec3[k++] = vec1[i];
	}

	for(j = 0; j < dim2; j++)
	{
		if(!aparece(vec3, k, vec2[j]))
		{
			vec3[k++] = vec2[j];
		}
	}

	return k;
}

int
aparece(const int vector[], int dim, int elem)
{
	int aparece = FALSE;
	for(int i = 0; i < dim && !aparece; i++)
	{
		if(vector[i] == elem)
		{
			aparece = TRUE;
		}
	}

	return aparece;
}