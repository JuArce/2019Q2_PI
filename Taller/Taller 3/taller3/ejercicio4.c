#include <stdio.h>

#define CONVERTIR(x)	((x) >= '0' && (x) <= '9') ? (x) - '0' : (x)

void
main()
{
	printf("%d\n", CONVERTIR('9'));
}