#include <stdio.h>
#include <ctype.h>

#define LETRAS ('Z' - 'A' + 1)

void letras(char * string, char * sLetras);

int 
main()
{
	char s[LETRAS + 1];
	letras("Abracadabra Pata de Cabra", s);
	printf("%s\n", s);

	letras("1234556 ()", s);
	printf("%s\n", s);

	letras("1x234Zx56 () 0x", s);
	printf("%s\n", s);

	return 0;
}

void
letras(char * string, char *sLetras)
{
	int i = 0;
	int j = 0;
	int posicion;

	for(int i = 0; i < LETRAS; i++) //Llena con ceros el string
	{
		sLetras[i] = 0;
	}

	while(string[i])
	{
		if(isalpha(string[i]))
		{
			posicion = toupper(string[i]) - 'A';
			sLetras[posicion] = toupper(string[i]);
		}
		i++;
	}

	for(int i = 0; i < LETRAS; i++) //Elimina los ceros del string, es decir solo deja las letras.
	{
		if(sLetras[i] != 0)
		{
			sLetras[j++] = sLetras[i];
		}
	}

	sLetras[j] = '\0';

	return;
}