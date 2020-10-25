#include <stdio.h>
#include <stdlib.h>
#include "bagADT.h"

typedef struct node
{
	elemType elem;
	size_t cant;
	struct node * tail;
}node;

typedef struct bagCDT
{
	size_t size;
	node * first;
	node * iter;
}bagCDT;


bagADT 
newBag()
{
	return calloc(1, sizeof(bagCDT));
}

size_t 
add(bagADT b, elemType e)
{
	size_t cant;
	bag->first = addRec(bag->first, e, &(b->size), &cant);
	return cant;
}

static node *
addRec(node * first, elemType elem,size_t * size, size_t * cant)
{
	if(first == NULL || (c = compare(first->elem, elem)) > 0)
	{
		node * aux = calloc(1 * sizeof(node));
		aux->elem = elem;
		(aux->cant)++;
		aux->tail = first;
		(*size)++;
		*cant = aux->cant;
		return aux;
	}

	if(c == 0)
	{
		(first->cant)++;
		*cant = aux->cant;
		return first;
	}

	first->tail = addRec(first->tail, elem, size);
	return first;
}

size_t 
remove(bag ADT b, elemType e)
{

}

size_t 
count(bagADT b, elemType e)
{

}

size_t 
size(bagADT b)
{
	return b->size;
}

void
freeBag(bagADT bag);

elemType 
mostPopular(bagADT b)
{

}