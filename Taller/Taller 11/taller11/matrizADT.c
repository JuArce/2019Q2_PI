#include <stdio.h>
#include <stdlib.h>

#include "matrizADT.h"

typedef struct tFila
{
	int dimCol; //Cantidad de columnas
	elementType * elems;
	elementType max;
	char * ocuppied; //Indica si hay un elemento en la posicion con 0 y 1
}tFila;

typedef struct matrixCDT
{
	struct tFila *filas;
	int dimFil; //Cantidad de filas
}matrixCDT;

static int isEmptyMatrix(matrixCDT m);

/* Crea una nueva matriz de elementos enteros 
** Inicialmente la matriz está vacía
** Si no se pudo crear retorna NULL.
 */
matrixADT 
newMatrix() //Ready
{
	return calloc(1, sizeof(matrixCDT));
}
 
/* Libera todos los recursos reservados por el TAD */
void 
freeMatrix(matrixADT m)
{

}
 
/* Agrega un elemento a la matriz. Si no lo pudo agregar o los parámetros 
** son incorrectos retorna cero, caso contrario 1
** Si la posición estaba ocupada pisa el elemento que había
** De ser necesario agranda la matriz
** m: matriz
** row: fila (mayor o igual a cero)
** col: columna ( mayor o igual a cero)
** elem: valor a insertar.
 */
int 
setElement(matrixADT m, size_t row, size_t col, elementType elem)
{
	if(m->dimFil == 0)
	{
		m->filas = calloc(row, sizeof(tFila));
		m->dimFil = row;
	}
	else if(row > m->fils)
	{
		m->filas = realloc(m->filas, (row)* sizeof(tFila));
		m->dimFil = row;
	}

	if(m->filas[row-1].dimCol == 0)
	{
		m->filas[row-1].elems = malloc((col) * sizeof(elementType));
		m->filas[row-1].ocuppied = calloc(col, sizeof(char));
		m->filas[row-1].dimCol = col;
	}
	else if(col > m->filas[row-1].dimCol)
	{
		m->filas[row-1].elems = realloc(m->filas[row-1].elems, col * sizeof(elementType));
		m->filas[row-1].ocuppied = realloc(m->filas[row-1].ocuppied, col * sizeof(char));
		m->filas[row-1].dimCol = col;
	}



}
 
/* Si existe un elemento en la posición [row][col], lo deja en out y retorna 1. 
** Si no había un elemento en esa posición retorna 0.
 */
int 
getElement(matrixADT m, size_t row, size_t col, elementType * out)
{
	if(isEmptyMatrix(m))
	{
		return 0;
	}

	if(row <= m->dimFil && col <= m->filas->dimCol)
	{
		if(m->filas[row].ocuppied[col])
		{
			*out = m->filas[row].elems[col];
			return 1;
		}
	}
	else
	{
		return 0;
	}
}
 
/* Cantidad de filas que tiene la matriz */
size_t 
rows(matrixADT m) //Ready
{
	return m->dimFils;
}
 
/* Retorna un vector con el mayor elemento de cada fila. 
** La cantidad de elementos del vector será rows(m) 
** Si una fila no tiene elementos, el máximo de la misma será min.
 */
elementType * 
maxElements(matrixADT m, elementType min) //Ready
{
	if(isEmptyMatrix(m))
	{
		return NULL;
	}

	elementType * aux = malloc(sizeof((m->dimFil) * sizeof(elementType)));

	for(int i = 0; i < m->dimFil; i++)
	{
		if(m->filas[i].dimCol == 0)
		{
			aux[i] = min;
		}
		else
		{
			aux[i] = m->filas[i].max;
		}
	}

	return aux;
}

static int 
isEmptyMatrix(matrixCDT m) //Ready
{
	return m->dimFil == 0;
}
