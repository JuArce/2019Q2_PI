#include <stdio.h>
#include <string.h>

#define TRUE 1 
#define FALSE 0

int strend(const char * s, const char * t);

int
main()
{
	char * s = "La casa de pedro es linda";
	char * t = "de pedro es linda";
	printf("%d\n", strend(s, t));
	return 1;
}

int
strend(const char * s, const char * t)
{
	int i = strlen(s);
	int j = strlen(t);
	int aparece = TRUE;


	if(i > j)
	{
		while(j && aparece)
		{
			if(s[i - 1] != t[j - 1])
			{
				aparece = FALSE;
			}
			i--; j--; 
		}
	}
	else
	{
		aparece = FALSE;
	}

	return aparece;
}