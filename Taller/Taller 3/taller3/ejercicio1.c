#include <stdio.h>
#include "getnum.h"

void
main()
{
	double num = getdouble("Ingrese un número real\n");
	int dec = (int)num; 
	int sumaDigitos = 0;
	printf("%f\t%d\n", num, dec);

	while(dec)
	{
		sumaDigitos += dec % 10;
		dec /= 10;
	}

	printf("Suma de digitos: %d\n", sumaDigitos);
}