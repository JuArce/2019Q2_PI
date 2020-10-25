#include <stdio.h>

#define DELTA 'a' - 'A'
void
main()
{
	char c = getchar();
	printf("%c\n", (c >= 'a' && c <= 'z')? c - (DELTA) : c);
}