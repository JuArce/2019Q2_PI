#include <stdio.h>
#include "getnum.h"

#define TRUE 1
#define FALSE 0

int esPrimo(int);

void
main()
{
	int n = getint("Imprimir los n primeros primos\n");
	
	printf("\nLos %d primero primos son:\n", n);

	for(int candidato = 2; n > 0; candidato++)
	{
		if(esPrimo(candidato)) //Si el candidato es primo lo imprime y descuenta la cantidad de primos a imprimir.
		{
			printf("%d:\t%d\n",n, candidato);
			n--;
		}
	}
}

int 
esPrimo(int n)
{
	int respuesta = TRUE; //Asumimos que el número es primo

	if(n == 0 || n == 1) //Si es 0 o 1 no es primo. Son casos especiales
	{
		respuesta = FALSE;
	}

	for(int i = 2; respuesta && i * i <= n; i++)
	{
		if(n % i == 0)
		{
			respuesta = FALSE; //Si el número es divisible por algún i < raiz(n) entonces el número no es primo
		}
	}

	return respuesta;
} 