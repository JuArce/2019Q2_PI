#include <stdio.h>
#include "getnum.h"

void
main()
{
	int a = getint("Ingrese un entero\n");
	int b = getint("Ingrese otro entero\n");

	printf("%d %s es múltiplo de %d\n", b, (b % a == 0) ? "sí" : "no", a);
	//b es divisible por a entonces b es múltiplo de a
}