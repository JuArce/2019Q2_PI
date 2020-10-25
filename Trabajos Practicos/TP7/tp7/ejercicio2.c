#include <stdio.h>
#include "getnum.h"

#define TRUE 1
#define FALSE 0

#define BORRA_BUFFER while(getchar()!='\n')

void leerBases(int *bEnt, int *bSal);
int aBaseDiez(int *entrada, int *salida, int *bEnt);
void deBaseDiez(int *entrada, int *salida, int *bSal);


int 
main()
{
 	int bEnt, bSal, nEntrada, nSalida, aux;
 	int numOK;

 	do
 	{
 		leerBases(&bEnt, &bSal);
 	}while((bEnt < 2 || bEnt > 10) && (bSal < 2 || bEnt > 10));

 	nEntrada = getint("Ingrese un numero en base %d\n", bEnt);

 	numOK = aBaseDiez(&nEntrada, &aux, &bEnt);

 	if(numOK == TRUE)
 	{
 		deBaseDiez(&aux, &nSalida, &bSal);
 		printf("%d en base %d, equivale a %d en base %d\n", nEntrada, bEnt, nSalida, bSal);
 	}
 	else
 	{
 		printf("Valores incorrectos\n");
 	}
}

void 
leerBases(int *bEnt, int *bSal)
{
 	int flag;

 	do
 	{
 	printf("Ingrese las bases con el siguiente formato '< bEntrada > bSalida'\n");
 	printf("Las bases deben estar entre 2 y 10\n");
 	flag = scanf("< %d > %d", bEnt, bSal);
 	BORRA_BUFFER;
	}while(flag != 2);

	return;
}

int
aBaseDiez(int *entrada, int *salida, int *bEnt)
{
 	int potencia = 1, aux, resto;
 	int numOK = TRUE;
 	*salida = 0;

 	for(aux = *entrada; aux > 0 && numOK; aux /= 10, potencia *= *bEnt)
 	{
 		resto = aux % 10;
 		if(resto > *bEnt)
 		{
 			numOK = FALSE;
 		}
 		else
 		{
 			*salida += resto * potencia;
 		}
 	}

 	return numOK;
}

void
deBaseDiez(int *entrada, int *salida, int *bSal) //Transforma de base 10 a base *bSal
{
	int resto, aux, potencia = 1;
	*salida = 0;

	for(aux = *entrada; aux > 0; aux /= *bSal, potencia *= 10)
	{
		resto = aux % *bSal;
		*salida += resto * potencia;
	}

	return;
}
