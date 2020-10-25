#include <stdio.h>

void factorial(int n, int * fact);
//int factorialRecursivo(int n);

int
main()
{
	int f;
	factorial(8, &f);
	printf("%d\n", f);
}

/*void
factorial(int n, int * fact)
{
	*fact = factorialRecursivo(n);
	return ;
}

int 
factorialRecursivo(int n)
{
	if(n == 0)
	{
		return 1;
	}

	return n * factorialRecursivo(n - 1);
}*/


void 
factorial(int n, int * fact)
{
	if(n == 0)
	{
		*fact = 1;
		return;
	}
	factorial(n-1, fact);
	*fact *= n;
	return;
}