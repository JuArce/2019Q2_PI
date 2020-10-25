#include "stackADT.h"

#define BLOQUE 5

typedef struct stackCDT
{

	elemType * elems;
	int size; //Cantidad de elementos (size <= dim)
	int dim; //Espacio reservado en memoria
}stackCDT;

stackADT 
newStack(void)
{
	return calloc(1, sizeof(stackCDT));
}

void 
freeStack(stackADT stack)
{
	free(stack->elems);
	free(stack);
	return;
}

int 
isEmpty(stackADT stack)
{
	return stack->size == 0;
}

void 
push(stackADT stack, elemType elem)
{
	if(stack->size == stack->dim)
	{
		stack->elems = realloc(stack->elems, (dim + BLOQUE) * sizeof(elemType));
		stack->dim += BLOQUE;
	}

	stack->elems[stack->size] = elem;
	stack->size++;
	return;
}

elemType
pop(stackADT stack)
{
	if(isEmpty(stack))
	{
		exit(1);
	}

	return stack->elems[--stack->size];
}