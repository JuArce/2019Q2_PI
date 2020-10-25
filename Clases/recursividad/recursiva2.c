#include <stdio.h>

int potencia(int base, int exp);

int
main()
{
	printf("%d\n", potencia(0, 0));
	return 0;
}

int
potencia(int base, int exponente)
{
	if(exponente == 0)
	{
		return 1;
	}

	return base * potencia(base, exponente - 1);
}
/*
int
potencia(int base, int exponente)
{
	if(exponente == 1)
	{
		return base;
	}

	return base * potencia(base, exponente - 1);
}*/