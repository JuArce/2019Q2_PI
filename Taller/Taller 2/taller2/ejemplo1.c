#include <limits.h>
#include <stdio.h>

int
main()
{
	char a, b;
	a = 100;
	b = (unsigned char)200 + a;
	printf("%d\n",b);

	signed char c;
	c = CHAR_MAX + 1;
	printf("%d\n", c);

	unsigned char d;
	d = UCHAR_MAX + 1;
	printf("%d\n", d);

	int e, f, g;
	e = 'a' - 'b' + '\0';
	f = '9' - 0;
	g = '9' - '0';
	printf("e: %d\tf: %d\tg: %d\n", e, f, g);
}