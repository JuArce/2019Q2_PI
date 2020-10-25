#include <stdio.h>

int factorial(int n);

int
main()
{
	printf("%d\n", factorial(6));
	return 0;
}

int
factorial(int n)
{
	if(n == 0 || n == 1)
	{
		return 1;
	}

	return n * factorial(n-1);
}