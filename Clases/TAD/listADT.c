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
	size_t size;
	node * first;
	node * iter;
}listCDT;

static void freeListRec(node * first);
static node * addRec(node * first, elemType elem, size_t * size);
static node * removeRec(node * first, elemType elem, size_t * size);
static int containsRec(const node * first, elemType elem);
static elemType getRec(node * f, size_t i);
static node * mapRec(node * f, elemType(*fn)(elemType elem));
static elemType reduceRec(node * f, elemType init, elemType(* fn)(elemType e1, elemType e2));

listADT 
newList()
{
	return calloc(1, sizeof(listCDT));
}

void 
freeList(listADT l)
{
	freeListRec(l->first);
	free(l);
	return;
}

static void
freeListRec(node * first)
{
	if(first == NULL)
	{
		return;
	}

	freeListRec(first->tail);
	free(first);
	return;
}

void 
add(listADT l, elemType elem)
{
	l->first = addRec(l->first, elem, &(l->size));
}

static node *
addRec(node * first, elemType elem, size_t * size)
{
	int c;

	if(first == NULL || (c = compare(first->elem, elem)) > 0)
	{
		node * aux = malloc(1 * sizeof(node));
		aux->elem = elem;
		aux->tail = first;
		(*size)++;
		return aux;
	}

	if(c == 0)
	{
		return first;
	}

	//if(c > 0)
	first->tail = addRec(first->tail, elem, size);
	return first;
}

int 
removeElem(listADT l, elemType elem)
{
	size_t auxSize = l->size;
	l->first = removeRec(l->first, elem, &(l->size));
	return auxSize != l->size;
}

static node *
removeRec(node * first, elemType elem, size_t * size)
{
	int c;
	if(first == NULL || (c = compare(first->elem, elem)) > 0)
	{
		return first;
	}

	if(c == 0)
	{
		node * aux = first->tail;
		free(first);
		(*size)--;
		return aux;
	}

	first->tail = removeRec(first->tail, elem, size);
	return first;
}

int 
contains(const listADT l, elemType elem)
{
	if(l->size == 0)
	{
		return 0;
	}

	return containsRec(l->first, elem);

}

static int
containsRec(const node * first, elemType elem)
{
	int c;
	if(first == NULL || (c = compare(first->elem, elem)) > 0)
	{
		return 0;
	}

	if(c == 0)
	{
		return 1;
	}

	return containsRec(first->tail, elem);
}

size_t 
size(const listADT l)
{
	return l->size;
}

int 
isEmpty(const listADT l)
{
	return l->size == 0; 
}

elemType 
get(const listADT l, size_t index)
{
	if(index >= l->size)
	{
		exit(1);
	}

	return getRec(l->first, index);
}

static elemType
getRec(node * f, size_t i)
{
	if(i == 0)
	{
		return f->elem;
	}

	return getRec(f->tail, i - 1);
}

void
toBegin(listADT l)
{
	l->iter = l->first;
	return;
}

elemType 
next(listADT l)
{
	elemType aux = l->iter->elem;
	l->iter = l->iter->tail;
	return aux;
}

int
hasNext(listADT l)
{
	return l->iter != NULL;
}

listADT
map(const listADT l, elemType(*fn)(elemType elem))
{
	listADT nL = newList();
	nL->first = mapRec(l->first, fn);
	nL->size = l->size;
	return nL;
}

static node *
mapRec(node * f, elemType(*fn)(elemType elem))
{
	if(f == NULL)
	{
		return NULL;
	}

	node * aux = malloc(sizeof(node));
	aux->elem = fn(f->elem);
	aux->tail = mapRec(f->tail, fn);
	return aux;
}

/*elemType
reduce(listADT l, elemType init, elemType(* fn)(elemType e1, elemType e2))
{
	elemType aux = init;
	node * auxNode = l->first;
	while(auxNode != NULL)
	{
		aux = fn(aux, auxNode->elem);
		auxNode = auxNode->tail;
	}
	return aux;
}
*/

elemType
reduce(listADT l, elemType init, elemType(* fn)(elemType e1, elemType e2))
{
	return reduceRec(l->first, init, fn);
}

static elemType 
reduceRec(node * f, elemType init, elemType(* fn)(elemType e1, elemType e2))
{
	if(f == NULL)
	{
		return init;
	}

	init = fn(f->elem, reduceRec(f->tail, init, fn));
	return init;
}
