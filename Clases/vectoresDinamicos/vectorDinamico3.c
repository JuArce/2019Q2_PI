#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getnum.h"

#define BLOQUE 5
#define MAX 20

int getLine(char s[], size_t max);
void imprimirNombres(char * nombres[], size_t jugadores);

int
main()
{
	int jugadores = getint("ingrese Cantidad de Jugadores: \n");
	int dim; //Cantidad de caracteres de cada nombre
	char aux[MAX + 1];
	char ** nombres;

	nombres = malloc(jugadores * sizeof(char *));

	for(int i = 0; i < jugadores; i++)
	{
		printf("Ingrese nombre jugador %d:", i + 1);
		dim = getLine(aux, MAX);
		nombres[i] = malloc(dim + 1);
		strcpy(nombres[i], aux);		
	}

	imprimirNombres(nombres, jugadores);

	return 0;
}

int
getLine(char s[], size_t max)
{
	int i = 0;
	int c;

	while((c = getchar()) != '\n' && c != EOF)
	{
		if(i < max)
		{
			s[i++] = c;
		}
	}

	s[i] = 0;
	return i;
}

void 
imprimirNombres(char * nombres[], size_t jugadores)
{
	for(int i = 0; i < jugadores; i++)
	{
		printf("Jugador %d: %s\n", i + 1, nombres[i]);
	}

	return;
}