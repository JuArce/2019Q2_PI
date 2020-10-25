#include <stdio.h>

int mcd(int a, int b);

int
main()
{
	printf("%d\n", mcd(1235, 375));
}

int
mcd(int a, int b)
{
	if(b == 0)
	{
		return a;
	}
	return mcd(b, a % b);
}