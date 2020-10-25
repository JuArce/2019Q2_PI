#include <stdio.h>
#include <stdlib.h>
#include "random.h"

#define BLOQUE 5

typedef struct
{
	int x;
	int y;
}tPunto;

int moverParticula(int radio, int direcciones[][2]); //Mueve la particula hasta que salga del circulo. Retorna la cantidad de movimientos.
void imprimirDatos(int radio, int pasos);

int
main()
{
	randomize();
	int direcciones[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
	int pasos;

	printf("Radio\tTiempo\tRadio/Tiempo\n");
	for(int radio = 1; radio < 11; radio++)
	{
		pasos = moverParticula(radio, direcciones);
		imprimirDatos(radio, pasos);
	}
	return 0;
}

int
moverParticula(int radio, int direcciones[][2])
{
	tPunto * puntos = malloc(BLOQUE * sizeof(tPunto));
	puntos[0].x = 0;
	puntos[0].y = 0;
	int i = 1;
	int aleatorio;
	int modulo = 0;
	while(modulo < radio * radio)
	{
		if(i % BLOQUE == 0)
		{
			puntos = realloc(puntos, (i + BLOQUE) * sizeof(tPunto));
		}
		aleatorio = randInt(0,3);
		//printf("%d\n", aleatorio);
		puntos[i].x = puntos[i-1].x + direcciones[aleatorio][0];
		puntos[i].y = puntos[i-1].y + direcciones[aleatorio][1];
		//printf("dx: %d\tdy: %d\n", direcciones[aleatorio][0], direcciones[aleatorio][1]);
		//printf("x: %d\ty: %d\n", puntos[i].x, puntos[i].y);
		modulo = puntos[i].x * puntos[i].x + puntos[i].y * puntos[i].y;
		i++;
	}

	free(puntos);

	return i-1;
}

void
imprimirDatos(int radio, int pasos)
{
	printf("%d\t%d\t%g\n", radio, pasos, (float)radio/pasos);
	return;
}
