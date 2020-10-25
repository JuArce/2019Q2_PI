#include <stdio.h>

int numerosAmigos(const int a, const int b);
int sumaDivisores(const int a);

int 
main()
{
	printf("%s\n", (numerosAmigos(220, 284) ? "SI" : "NO"));
	printf("%s\n", (numerosAmigos(10, 12) ? "SI" : "NO"));
	printf("%s\n", (numerosAmigos(1184, 1210) ? "SI" : "NO"));
	printf("%s\n", (numerosAmigos(220, 2840) ? "SI" : "NO"));
}

int
numerosAmigos(const int a, const int b)
{
	if(a == sumaDivisores(b) && b == sumaDivisores(a))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int
sumaDivisores(const int a)
{
	int suma = 0;
	for(int i = 1; i < a; i++)
	{
		if(a % i == 0)
		{
			suma += i;
		}
	}
	return suma;
}