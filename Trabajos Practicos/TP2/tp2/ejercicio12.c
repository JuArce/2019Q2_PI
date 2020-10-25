#include <stdio.h>

void 
main()
{
	char c = getchar();
	printf("El carácter %c %s es una letra\n", c, ((c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z')) ? "sí" : "no");
}
