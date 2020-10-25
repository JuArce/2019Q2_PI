#include <stdio.h>

#define MAX 100 

void eliminarEspaciosExtra(char * string);

int
main()
{
	char string[MAX] = "Hola        mundo,  chau  mundo";
	printf("%s\n", string);
	eliminarEspaciosExtra(string);
	printf("%s\n", string);
}

void
eliminarEspaciosExtra(char * string)
{
	int i = 0, j = 0;
	while(string[i])
	{		
		while(string[i] && string[i] == ' ' && string [i+1] == ' ')
		{
			i++;			
		}

		string[j++] = string[i++];
	}	
	string[j] = '\0';
}