#include <stdio.h>
#include <stdlib.h>
#include "listADT.h"

typedef struct node
{
	elemType elem;
	struct node * tail;
}node;

typedef struct listCDT
{
	node * first;
	node * iter;

	node * firstAsc;
	node * iterAsc;	
}listCDT;


static node * addAscRec(node * firstAsc, elemType elem);
static node * addRec(node * first, elemType elem);


listADT 
newList()
{
	return calloc(1, sizeof(listCDT));
}

void 
add(listADT list, elemType elem)
{
	list->first = addRec(list->first, elem);
	list->firstAsc = addAscRec(list->firstAsc, elem);
	return;
}

static node *
addAscRec(node * firstAsc, elemType elem)
{
	int c;
	if(firstAsc == NULL || (c = compare(firstAsc->elem, elem)) > 0)
	{
		node * aux = malloc(sizeof(node));
		aux->elem = elem;
		aux->tail = firstAsc;
		return aux;
	}

	if(c == 0)
	{
		return firstAsc;
	}

	firstAsc->tail = addAscRec(firstAsc->tail, elem);
	return firstAsc;
}

static node * 
addRec(node * first, elemType elem)
{
	int c;
	if(first == NULL)
	{
		node * aux = malloc(sizeof(node));
		aux->elem = elem;
		aux->tail = NULL;
		return aux;
	}

	if((c= compare(first->elem, elem)) == 0)
	{
		return first;
	}

	first->tail = addRec(first->tail, elem);
	return first;
}

void 
toBegin(listADT list)
{
	list->iter = list->first;
	return;
}

int 
hasNext(listADT list)
{
	return list->iter != NULL;
}	

elemType 
next(listADT list)
{
	if(list->iter == NULL)
	{
		exit(1);
	}

	elemType aux = list->iter->elem;
	list->iter = list->iter->tail;
	return aux;
}

void 
toBeginAsc(listADT list)
{
	list->iterAsc = list->firstAsc;
}

int 
hasNextAsc(listADT list)
{
	return list->iterAsc != NULL;
}	

elemType 
nextAsc(listADT list)
{
	if(list->iterAsc == NULL)
	{
		exit(1);
	}

	elemType aux = list->iterAsc->elem;
	list->iterAsc = list->iterAsc->tail;
	return aux;
}
