#include <stdio.h>
#include "getnum.h"

void
main()
{
	unsigned int num = getint("Ingrese un entero positivo\n");
	printf("%d\n", num>>1);
}