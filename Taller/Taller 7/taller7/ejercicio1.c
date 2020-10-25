#include <stdio.h>

#define MAX 100

void eliminaRepetidos(char * string);

int
main()
{
	char string[] = "aaaaaaa aaaa";
	printf("%s\n", string);
	eliminaRepetidos(string);
	printf("%s\n", string);
	return 0;
}
/*
void
eliminaRepetidos(char * string)
{
	int i = 0, j = 0;

	while(string[i])
	{
		while(string[i] == string[i+1])
		{
			i++;
		}

		string[j++] = string[i++];
	}

	string[j] = '\0';
	return;
}
*/
void
eliminaRepetidos(char * string)
{
	char * aux = string;
	char * auxSalida = string;

	while(*aux)
	{
		while(*aux == *(aux + 1))
		{
			aux++;
		}

		*auxSalida++ = *aux++;
	}

	*auxSalida = '\0';

	return;
}