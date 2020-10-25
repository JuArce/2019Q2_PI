#include <stdio.h>
#include "getnum.h"

void
main()
{
	int num1 = getint("Ingrese un entero\n");
	int num2 = getint("Ingrese otro entero\n");

	printf("El promedio es: %.2f\n", ((float)num1 + num2) / 2);
	printf("La suma es: %d\n", num1 + num2);
	if(num1 != num2)
	{
		printf("El menor es: %d\n", (num1 < num2)? num1 : num2);
		printf("El mayor es: %d\n", (num1 > num2)? num1 : num2);
	}
	printf("%s iguales\n", (num1 == num2)? "Son" : "No son");
}