#include <stdio.h>
#include <stdlib.h>
#include "moveToFrontADT.h"


typedef struct node
{
	elemType elem;
	struct node * tail;
}node;

typedef struct moveToFrontCDT
{
	size_t size;
	node * first;
	node * iter;
}moveToFrontCDT;


static node * addRec(node * first, elemType elem, size_t * size);
//static elemType * getRec(node ** current, elemType elem, node ** first);

moveToFrontADT 
newMoveToFront()
{
	return calloc(1, sizeof(moveToFrontCDT));
}

unsigned int 
add(moveToFrontADT moveToFront, elemType elem)
{
	size_t auxSize = moveToFront->size;
	moveToFront->first = addRec(moveToFront->first, elem, &(moveToFront->size));
	return auxSize != moveToFront->size;
}

static node *
addRec(node * first, elemType elem, size_t * size)
{
	if(first == NULL)
	{
		node * aux = malloc(sizeof(node));
		aux->elem = elem;
		aux->tail = NULL;
		(*size)++;
		return aux;
	}

	int c;
	if((c = compare(first->elem, elem)) == 0)
	{
		return first;
	}

	first->tail = addRec(first->tail, elem, size);
	return first;
}

unsigned int 
size(moveToFrontADT moveToFront)
{
	return moveToFront->size;
}

void 
toBegin(moveToFrontADT moveToFront)
{
	moveToFront->iter = moveToFront->first;
}

int 
hasNext(moveToFrontADT moveToFront)
{
	return moveToFront->iter != NULL;
}

elemType 
next(moveToFrontADT moveToFront)
{
	elemType aux = moveToFront->iter->elem;
	moveToFront->iter = moveToFront->iter->tail;
	return aux;
}

elemType * 
get(moveToFrontADT moveToFront, elemType elem)
{
	//elemType * auxElem = getRec(&(moveToFront->first), elem, &(moveToFront->first));
	elemType * auxElem = calloc(1, sizeof(elemType));
	node ** current = &(moveToFront->first);
	int c;
	while(*current != NULL)
	{
		if((c = compare((*current)->elem, elem)) == 0)
		{
			*auxElem = (*current)->elem;

			node * aux = *current;
			*current = (*current)->tail;

			aux->tail = moveToFront->first;
			moveToFront->first = aux;
		}
		else
		{
			current = &((*current)->tail);
		}
	}

	return auxElem;
}

/*static elemType *
getRec(node ** current, elemType elem, node ** first)
{
	if(*current == NULL)
	{
		return NULL;
	}

	int c;
	if((c = compare((*current)->elem, elem)) == 0)
	{
		elemType * auxElem = malloc(sizeof(elemType));
		*auxElem = (*current)->elem;

		node * aux = *current;
		*current = (*current)->tail;

		aux->tail = *first;
		*first = aux;

		return auxElem;
	}

	return getRec((&(*current)->tail), elem, first);
}*/
