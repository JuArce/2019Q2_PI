#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOQUE 5

void crearPalos(char * palos[4], int cantPalos);

int
main()
{
	char * palos[4];
	int cantPalos = 4;
	crearPalos(palos, cantPalos);

	for(int i = 0; i < cantPalos; i++)
	{
		printf("%s\n", palos[i]);
	}

	return 0;
}

void crearPalos(char * palos[4], int cantPalos)
{	
	palos[0] = malloc(5);
	palos[1] = malloc(6);
	palos[2] = malloc(4);
	palos[3] = malloc(7);

	strcpy(palos[0], "Copa");
	strcpy(palos[1], "Basto");
	strcpy(palos[2], "Oro");
	strcpy(palos[3], "Espada");

	return;
}