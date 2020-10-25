#include <stdio.h>

void 
main()
{
	char c = getchar();
	char t = getchar();

	printf("El carácter %c es %s al carácter %c\n", c, (c == t)? "igual" : (c > t)? "mayor" : "menor" , t);
}