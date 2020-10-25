#include <stdio.h>
#include <math.h>

double diferenciaConsecutiva(const double vector[]);

int
main()
{
	double v1[] = {-12.2, 2.54, 3, 4.5, 5.5, 0};

	printf("Maxima diferencia: %g\n", diferenciaConsecutiva(v1));
}

double
diferenciaConsecutiva(const double vector[])
{
	double max = 0;

	for(int i = 0; vector[i+1] != 0; i++)
	{
		if(fabs(vector[i] - vector[i + 1]) > max)
		{
			max = fabs(vector[i] - vector[i + 1]);
		}
	}

	return max;
}