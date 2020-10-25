#include <stdio.h>

void regla(int n);

int 
main()
{
	regla(5);
	putchar('\n');
}

void
regla(int n)
{
	if (n > 0)
	{
		regla(n / 2);
		printf("%d\t", n);
		regla(n / 2);
		//printf("%d\n", n);
	}
	return;
}