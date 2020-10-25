#include <stdio.h>

int main()
{
	char a,b;
	char num;
	char ahex, bhex;

	a = getchar();
	b = getchar();

	if ( a >= '0' && a <= '9' && b >= '0' && b <= '9')
	{
   		num = (a - '0') * 10 + (b - '0');

   		ahex = num / 16 ;
   		ahex += (ahex >= 10) ? 'A' - 10 : '0';

   		bhex = num % 16;
   		bhex += (bhex >= 10) ? 'A' - 10 : '0';

   		printf("Dec = %d\taHex = %c\tbHex = %c\n", num, ahex, bhex);
	}

	return 0;
}
