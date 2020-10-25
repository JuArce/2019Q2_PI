#include <stdio.h>

#define MAXIMO(a, b)        ((a) > (b)) ? (a) : (b)

void
main()
{
	printf("El máximo es %d\n", MAXIMO(5, 10));
}

