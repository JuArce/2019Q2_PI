#include <stdio.h>

void 
main()
{
	char a = getchar();
	char b = getchar();

	printf("El mayor entre %c y %c es: %c\n", a, b, (a>b)? a : b);
}
