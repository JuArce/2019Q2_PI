#include <stdio.h>

#define MAX 100
#define TRUE 1
#define FALSE 0

int interseccion(const int vec1[], int dim1, const int vec2[], int dim2, int vec3[]);

int 
main()
{
	int v1[] = {1,2,3,4,5,6,7,8,9,10};
	int v2[] = {2,4,6,8,10,12,14,16,18,20};
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
	int i = 0, j = 0, k = 0;

	while(i < dim1 && j < dim2)
	{
		if(vec1[i] == vec2[j])
		{
			vec3[k++] = vec1[i];
			i++; j++;
		}
		else if(vec1[i] < vec2[j])
		{
			i++;
		}
		else if(vec1[i] > vec2[j])
		{
			j++;
		}
	}

	return k;
}