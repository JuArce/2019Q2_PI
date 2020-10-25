#include <stdio.h>

int ramasArbol(float alturaInicial, float alturaMinima);

int
main()
{
	printf("%d\n", ramasArbol(10, 0.1));

}

int 
ramasArbol(float alturaInicial, float alturaMinima)
{
	if(alturaInicial < alturaMinima)
	{
		return 0;
	}

	return 1 + 2 * ramasArbol(alturaInicial / 2, alturaMinima);
}