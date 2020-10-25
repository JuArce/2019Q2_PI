#include <stdio.h>
#include <ctype.h>

int cantVocales(char * string);
int esVocal(char letra);

int
main()
{
	char s[] = "Fernanda";
	int v = 0;
	printf("%d\n", cantVocales(s));
}

/*int
cantVocales(char * string, int vocales)
{

	if(*string == '\0')
	{
		return vocales;
	}
	if(esVocal(*string))
	{
		vocales++;
	}
	cantVocales(string + 1, vocales);
}*/

int
cantVocales(char * string)
{
	if(*string == '\0')
	{
		return 0;
	}
	if(esVocal(*string))
	{
		return 1 + cantVocales(string + 1);
	}
	return cantVocales(string + 1);
}

int esVocal(char letra)
{
	char aux = toupper(letra);
	if(aux == 'A' || aux == 'E' || aux == 'I' || aux == 'O' || aux == 'U')
	{
		return 1;
	}
	return 0;
}