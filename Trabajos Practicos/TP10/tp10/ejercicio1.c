#include <stdio.h>
#include "getnum.h"

typedef struct tFuncion
{
	char * nombre;
	double (*funcion)(int vec[], int dim);
}tFuncion;

int menu(tFuncion funciones[], int cantFunciones);
double promedio(int vec[], int dim);
double minimo(int vec[], int dim);
double maximo(int vec[], int dim);

int
main()
{
	int numeros[] = {1,2,3,4,5,6,7,8,7,6,5,4,3,2,1,9,-1,-2,-3};
	tFuncion funciones[] = {{"Promedio", promedio}, {"Minimo", minimo}, {"Maximo", maximo}};
	int dim = sizeof(numeros) / sizeof(numeros[0]);
	int cantFunciones = 3;

	int opcion;
	double resultado;

	do
	{
		opcion = menu(funciones, cantFunciones);
		if(opcion != cantFunciones + 1)
		{
			resultado = (funciones[opcion - 1].funcion)(numeros, dim);
			printf("%s: %g\n", funciones[opcion - 1].nombre, resultado);
		}
	}while(opcion != cantFunciones + 1);

	return 0;
}

int menu(tFuncion funciones[], int cantFunciones)
{
	int i;
	int opcion;
	do
	{
		for(i = 0; i < cantFunciones; i++)
		{
			printf("%d: %s\n", i + 1, funciones[i].nombre);
		}

		printf("%d: Salir\n", i + 1);

		opcion = getint("Seleccione una opcion: ");
	}while(opcion < 1 || opcion > cantFunciones + 1);

	return opcion;
}

double 
promedio(int vec[], int dim)
{
	int suma = 0;
	double promedio;

	for(int i = 0; i < dim; i++)
	{
		suma += vec[i];
	}

	promedio = suma/dim;
	return promedio;
}

double
minimo(int vec[], int dim)
{
	int min = vec[0];

	for(int i = 1; i < dim; i++)
	{
		if(vec[i] < min)
		{
			min = vec[i];
		}
	}

	return min;
}

double 
maximo(int vec[], int dim)
{
	int max = vec[0];

	for(int i = 1; i < dim; i++)
	{
		if(vec[i] > max)
		{
			max = vec[i];
		}
	}

	return max;
}