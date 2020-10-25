#include <stdio.h>

int esNulo(int vec[], int dim);

int
main()
{
	int vec[] = {0,0,0,0};
	printf("Vec %s nulo\n", esNulo(vec,4) ? "es" : "no es");
}

int
esNulo(int vec[], int dim)
{
	if(dim == 0)
	{
		return 1;
	}

	return vec[0] == 0 && esNulo(vec + 1, dim - 1);
}