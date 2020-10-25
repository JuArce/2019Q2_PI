#include <stdio.h>
#include <string.h>

int esCapicua(char * string, int longitud);

int
main()
{
	char s[] = "anitalavalatina";
	int l = strlen(s);
	printf("%s\n", esCapicua(s, l) ? "SI" : "NO");
}

int
esCapicua(char * string, int longitud)
{
	if( longitud <= 1)
	{
		return 1;
	}
	return string[0] == string[longitud - 1] && esCapicua(string + 1, longitud - 2);
}