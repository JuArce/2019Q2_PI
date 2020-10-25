#include <stdio.h>

int fibonacci(int n);

int
main()
{
	
}

int fibonacci(int n)
{
	if(n < 2)
	{
		return n;
	}

	return fibonacci(n - 1) + fibonacci(n - 2);
}