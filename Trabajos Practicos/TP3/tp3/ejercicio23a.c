#include <stdio.h>

int
main()
{
	int actual, anterior = '\0';
	while((actual = getchar()) != EOF)
	{
		if(actual != ' ' || anterior != ' ')
		{
			putchar(actual);
		}
		anterior = actual;
	}
}