#include <stdio.h>

void eliminaIguales(char * string1, char * string2);

int
main()
{
	char string1[] = "mantelito";
	char string2[] = "mantalita";
	eliminaIguales(string1, string2);
	printf("%s\n%s\n", string1, string2);
	return 0;
}

void
eliminaIguales(char * string1, char * string2)
{
	int i = 0, j = 0;
	int k = 0, r = 0; 
	
	while(string1[i] && string2[k])
	{
		if(string1[i] != string2[k])
		{
			string1[j++] = string1[i++];
			string2[r++] = string2[k++];
		}
		else
		{
			i++;
			k++;
		}
	}

	while(string1[i])
	{
		string1[j++] = string1[i++];
	}

	while(string2[k])
	{
		string2[r++] = string2[k++];
	}

	string1[j] = '\0';
	string2[r] = '\0';

	return;
}