#include <stdio.h>

int esCapicua(char *string, int longitud);

int
main()
{
	printf("%d\n", esCapicua("aola", 4));
	printf("%d\n", esCapicua("anna", 4));
	return 0;
}

int
esCapicua(char *string, int longitud)
{
	if(longitud <= 1)
	{
		return 1;
	}

	if(string[0] == string[longitud - 1])
		return esCapicua(string +1, longitud - 2);
	return 0;
}