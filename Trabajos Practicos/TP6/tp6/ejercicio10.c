#include <stdio.h>
#include "random.h"

#define FILAS 20
#define COLUMNAS 80
#define RANGO_MIN 0
#define RANGO_MAX 20
#define ESTRELLA 12 //Valor minimo para que exista una estrella en la coordenada i,j

void generarMatriz(int matrizIntensidades[FILAS][COLUMNAS], int filas, int columnas);
void imprimirMatrizIntensidades(int matriz[FILAS][COLUMNAS], int filas, int columnas);
void imprimirMatrizEstrellas(int matriz[FILAS][COLUMNAS], int filas, int columnas);
void analizarMatriz(int matrizIntensidades[FILAS][COLUMNAS], int matrizEstrellas[FILAS][COLUMNAS], int filas, int columnas);

int
main()
{
	randomize();
	int matrizIntensidades[FILAS][COLUMNAS];
	int matrizEstrellas[FILAS][COLUMNAS] = {{0}};

	generarMatriz(matrizIntensidades, FILAS, COLUMNAS);

	analizarMatriz(matrizIntensidades, matrizEstrellas, FILAS, COLUMNAS);

	printf("\nIntensidades\n\n");
	imprimirMatrizIntensidades(matrizIntensidades, FILAS, COLUMNAS);
	
	printf("\nEstrellas\n\n");
	imprimirMatrizEstrellas(matrizEstrellas, FILAS, COLUMNAS);

	return 0;
}

void 
generarMatriz(int matrizIntensidades[FILAS][COLUMNAS], int filas, int columnas)
{
	for(int i = 0; i < filas; i++)
	{
		for(int j = 0; j < columnas; j++)
		{
			matrizIntensidades[i][j] = randInt(RANGO_MIN, RANGO_MAX);
		}
	}
}

void 
imprimirMatrizIntensidades(int matriz[FILAS][COLUMNAS], int filas, int columnas)
{
	for(int i = 0; i < filas; i++)
	{
		for(int j = 0; j < columnas; j++)
		{
			printf("%d\t", matriz[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');
}

void 
imprimirMatrizEstrellas(int matriz[FILAS][COLUMNAS], int filas, int columnas)
{
	for(int i = 0; i < filas; i++)
	{
		for(int j = 0; j < columnas; j++)
		{
			printf("%c\t", matriz[i][j]);
		}
		putchar('\n');
	}
	putchar('\n');
}

void 
analizarMatriz(int matrizIntensidades[FILAS][COLUMNAS], int matrizEstrellas[FILAS][COLUMNAS], int filas, int columnas)
{
	double punto;
	for(int i = 1; i < filas - 1; i++) //omite los bordes
	{
		for(int j = 1; j < columnas - 1; j++) //omite los bordes
		{
			punto = (double)(matrizIntensidades[i][j] + 
					matrizIntensidades[i-1][j-1] + matrizIntensidades[i-1][j] + matrizIntensidades[i-1][j+1] +
					matrizIntensidades[i][j-1] + matrizIntensidades[i][j+1] + 
					matrizIntensidades[i+1][j-1] + matrizIntensidades[i+1][j] + matrizIntensidades[i+1][j+1]) / 9.0;
			if(punto > ESTRELLA)
			{
				matrizEstrellas[i][j] = '*';
			}
		}
	}
}