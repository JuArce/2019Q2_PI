#include <stdio.h>

void insertaDesde(char *string1, char *string2, char c);

int
main()
{
	char str1[20] = "manuel";
	char str2[] = "javi";
	insertaDesde(str1, str2, 'j');
	printf("%s\n", str1);
}

void 
insertaDesde(char *string1, char *string2, char c)
{
	while(*string1 && *string1 != c)
	{
		string1++;
	}

	if(*string1 == c)
	{
		while(*string2)
		{
			*string1++ = *string2++;
		}
	}

	*string1 = '\0';
	return;
}