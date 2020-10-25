#include <stdio.h>
#include <stdlib.h>
#include "multiSetADT.h"


typedef struct node
{
	elemType elem;
	size_t count;
	struct node * tail;
}node;

typedef struct multiSetCDT
{
	size_t size;
	size_t maxCount;
	node * first;
}multiSetCDT;


static node * addRec(node * first, elemType elem, size_t * size, size_t * maxCount, size_t * auxCount);
static unsigned int countRec(node * first, elemType elem);
static int removeRec(node * first, elemType elem, size_t * size);
static void removeAllRec(node * first, elemType elem, size_t * size);
static elemType * minElementsRec(node * first, elemType * vec, int * dim, size_t maxCount);


multiSetADT 
newMultiSet()
{
	return calloc(1, sizeof(multiSetCDT));
}

unsigned int 
add(multiSetADT multiSet, elemType elem)
{
	size_t auxCount;
	multiSet->first = addRec(multiSet->first, elem, &(multiSet->size), &(multiSet->maxCount), &auxCount);
	return auxCount;
}

static node * 
addRec(node * first, elemType elem, size_t * size, size_t * maxCount, size_t * auxCount)
{
	int c;
	if(first == NULL || (c = compare(first->elem, elem)) > 0)
	{
		node * aux = calloc(1, sizeof(node));
		aux->elem = elem;
		aux->count++;
		aux->tail = first;
		(*size)++;
		*auxCount = aux->count;
		if(aux->count > *maxCount)
		{
			*maxCount = aux->count;
		}
		return aux;
	}

	if(c == 0)
	{
		(first->count)++;
		*auxCount = first->count;
		if(first->count > *maxCount)
		{
			*maxCount = first->count;
		}
		return first;
	}

	first->tail = addRec(first->tail, elem, size, maxCount, auxCount);
	return first;
}

unsigned int 
count(const multiSetADT multiSet, elemType elem)
{
	return countRec(multiSet->first, elem);
}

static unsigned int
countRec(node * first, elemType elem)
{
	int c;
	if(first == NULL || (c = compare(first->elem, elem)) > 0)
	{
		return 0;
	}

	if(c == 0)
	{
		return (unsigned int)first->count;
	}

	return countRec(first->tail, elem);
}

unsigned int 
size(const multiSetADT multiSet)
{
	return multiSet->size;
}

int 
removeElem(multiSetADT multiSet, elemType elem)
{
	return removeRec(multiSet->first, elem, &(multiSet->size));
}

static int
removeRec(node * first, elemType elem, size_t  * size)
{
	int c;
	if(first == NULL || (c = compare(first->elem, elem)) > 0)
	{
		return 0;
	}

	if(c == 0)
	{
		(first->count)--;
		if(first->count == 0)
		{
			node * aux = first;
			first = first->tail;
			free(aux);
			(*size)--;
			return 0;
		}
		return first->count;
	}

	return removeRec(first->tail, elem, size);
}

void 
removeAll(multiSetADT multiSet, elemType elem)
{
	removeAllRec(multiSet->first, elem, &(multiSet->size));
	return;
}

static void
removeAllRec(node * first, elemType elem, size_t * size)
{	
	int c;
	if(first == NULL || (c = compare(first->elem, elem)) > 0)
	{
		return;
	}

	if(c == 0)
	{
		node * aux = first;
		first = first->tail;
		free(aux);
		(*size)--;
		return;
	}

	removeAllRec(first->tail, elem, size);
}

elemType * 
minElements(const multiSetADT multiSet, int * dim)
{
	*dim = 0;
	elemType * vec = NULL;
	//vec = minElementsRec(multiSet->first, vec, dim, multiSet->maxCount);

	node * aux = multiSet->first;
	while(aux != NULL)
	{
		if(aux->count < multiSet->maxCount)
		{
			vec = realloc(vec, (*dim + 1) * sizeof(elemType));
			vec[(*dim)] = aux->elem;
			(*dim)++;
		}
		aux = aux->tail;
	}

	return vec;
}

/*static elemType *
minElementsRec(node * first, elemType * vec, int * dim, size_t maxCount)
{
	if(first == NULL)
	{
		return vec;
	}

	if(first->count < maxCount)
	{
		vec = realloc(vec, (*dim + 1) * sizeof(elemType));
		vec[(*dim)] = first->elem;
		(*dim)++;
	}

	return minElementsRec(first->tail, vec, dim, maxCount);
}*/