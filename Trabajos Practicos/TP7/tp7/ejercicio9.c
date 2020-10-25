#include <stdio.h>
#include <math.h>
#include "getnum.h"
#include "random.h"

#define TRUE 1
#define FALSE 0
#define MAX 90 //Cota superior numeros permitidos en los cartones
#define FILS 3
#define COLS 5

typedef int TipoLinea[5];
typedef TipoLinea TipoCarton[3];

int jugar(int bolillero[], TipoCarton jugador1, TipoCarton Jugador2);
void generarCarton(TipoCarton carton);
int sacarBolilla(int bolillero[], int * cantBolillas);
int controlarCarton(TipoCarton carton, int bolilla);
void imprimirCarton(TipoCarton carton);
int buscarBolilla(TipoCarton carton, int bolilla);
int controlarLineas(TipoLinea linea);

int
main()
{
	randomize();

	int bolillero[MAX];
	for(int i = 0; i < MAX; i++) //Llena el bolillero del 1 al 90
	{
		bolillero[i] = i+1;
	}

	int ganadores;

	TipoCarton jugador1;
	TipoCarton jugador2;

	generarCarton(jugador1);
	generarCarton(jugador2);

	ganadores = jugar(bolillero, jugador1, jugador2);

	switch(ganadores)
	{
		case 1: printf("Gano el jugador 1\n"); break;
		case 2: printf("Gano el jugador 2\n"); break;
		case 3: printf("Ambos jugadores hicieron bingo\n"); break;
	}
}

void
generarCarton(TipoCarton carton)
{
	int random;
	int n = MAX;

	int numeros[MAX];
	for(int i = 0; i < MAX; i++)
	{
		numeros[i] = i + 1;
	}

	for(int i = 0; i < FILS; i++)
	{
		for(int j = 0; j < COLS; j++)
		{
			random = randInt(0, n-1);
			carton[i][j] = numeros[random];
			numeros[random] = numeros[--n];
 		}
	}

	return;
}

int
jugar(int bolillero[], TipoCarton jugador1, TipoCarton jugador2)
{
	int bingo = 0;
	int bolilla;
	int cantBolillas = MAX;
	int lineasCompletas = 0;
	int c;

	do
	{
		bolilla = sacarBolilla(bolillero, &cantBolillas);
		printf("\nBolilla: %d\n", bolilla);
		printf("\nBolillas restantes: %d\n", cantBolillas);

		lineasCompletas = controlarCarton(jugador1, bolilla);
		if(lineasCompletas == 3)
		{
			bingo += 1;
		}
		printf("\nJugador 1:\n");
		imprimirCarton(jugador1);

		lineasCompletas = controlarCarton(jugador2, bolilla);
		if(lineasCompletas == 3)
		{
			bingo += 1;
		}
		printf("\nJugador 2:\n");
		imprimirCarton(jugador2);
	}while(bingo == 0 && (c = getchar()) == '\n');
	
	return bingo;
}

int 
sacarBolilla(int bolillero[], int * cantBolillas)
{
	int random, bolilla;

	random = randInt(0, *cantBolillas - 1);
	bolilla = bolillero[random];
	bolillero[random] = bolillero[*cantBolillas - 1];
	(*cantBolillas)--;

	return bolilla;
}

int
controlarCarton(TipoCarton carton, int bolilla)
{
	int lineasCompletas = 0;

	buscarBolilla(carton, bolilla);
	for(int i = 0; i < FILS; i++)
	{
			if(controlarLineas(carton[i]))
			{
				lineasCompletas++;
			}
	}
	return lineasCompletas;
}

void 
imprimirCarton(TipoCarton carton)
{
	for(int i = 0; i < FILS; i++)
	{
		for(int j = 0; j < COLS; j++)
		{
			printf("%d\t", carton[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');
	return;
}

int 
buscarBolilla(TipoCarton carton, int bolilla)
{
	int aparece = FALSE;

	for(int i = 0; i < FILS && !aparece; i++)
	{
		for(int j = 0; j < COLS && !aparece; j++)
		{
			if(carton[i][j] == bolilla)
			{
				carton[i][j] = 0;
				aparece = TRUE;
			}
		}
	}

	return aparece;
}

int 
controlarLineas(TipoLinea linea)
{
	int lineaCompleta = TRUE;

	for(int i = 0; i < COLS && lineaCompleta; i++)
	{
		if(linea[i] != 0)
		{
			lineaCompleta = FALSE;
		}
	}

	return lineaCompleta;
}
