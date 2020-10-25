#include <stdio.h>
#include "getnum.h"
#define TRUE 1
#define FALSE 0
void
main()
{
	int numOk;
	int potencia = 1;
	int baseDiez = 0;
	int baseOcho;
	do
	{
		numOk = TRUE;
		baseOcho = getint("Ingrese un número base 8\n");
		for(int i = baseOcho; numOk && i; i /= 10)
		{
			if(i % 10 > 7)
			{
				numOk = FALSE;
			}
		}
	}while(numOk == FALSE);

	for(int aux = baseOcho; aux; potencia *=8, aux /= 10)
	{
		baseDiez += (aux % 10) * potencia;
	}
	printf("'%d' en base 8 corresponde a '%d' en base 10\n", baseOcho, baseDiez);
}