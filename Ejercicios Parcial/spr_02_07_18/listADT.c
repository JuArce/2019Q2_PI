#include <stdio.h>
#include <stdlib.h>
#include "listADT.h"

typedef struct node
{
	listElementT elem;
	struct node * next;
	struct node * prev;
}node;

typedef struct listCDT
{
	size_t size;
	node * first;
	node * last;
	node * iter;
}listCDT;



static int addBeforeRec(node * first, listElementT elem, listElementT newElem);
static int addAfterRec(node * first, listElementT elem, listElementT newElem);
static node * removeLastRec(node * last, listElementT elem, size_t * size, node ** first);
static void freeListRec(node * first);


listADT 
newList()
{
	return calloc(1, sizeof(listCDT));
}

int
insert(listADT list, listElementT elem)
{
	node * aux = malloc(sizeof(node)); //Uso calloc para que el next ya esté en NULL

	aux->elem = elem;
	aux->prev = list->last;
	aux->next = NULL;

	if(list->last != NULL)
	{
		list->last->next = aux; //Enlaza el nuevo ultimo a la cola del ultimo anterior
	}
	
	list->last = aux; //Actualiza el ultimo de listCDT

	if(list->first == NULL)
	{
		list->first = aux;
		list->first->prev = NULL;
	}

	(list->size)++;

	return 1;
}

int
size(listADT list)
{
	return list->size;
}

void toBegin(listADT list)
{
	list->iter = list->first;
	return;
}

int hasNext(listADT list)
{
	return list->iter != NULL;
}

listElementT next(listADT list)
{
	listElementT aux = list->iter->elem;
	list->iter = list->iter->next;
	return aux;
}

void
freeList(listADT list)
{
	freeListRec(list->first);
	free(list);
	return;
}

static void
freeListRec(node * first)
{
	if(first == NULL)
	{
		return;
	}

	freeListRec(first->next);
	free(first);
	return;
}



int 
addBefore(listADT list, listElementT elem, listElementT newElem)
{
	if(addBeforeRec(list->first, elem, newElem))
	{
		(list->size)++;

		if(list->first->prev != NULL) //Actualiza el first, en caso de que se haya introducido el newElem antes del first
		{
			list->first = list->first->prev;
		}

		return 1;
	}

	return 0;
}

static int
addBeforeRec(node * first, listElementT elem, listElementT newElem)
{	
	if(first == NULL)
	{
		return 0;
	}

	int c;
	if((c = compare(first->elem, elem)) == 0)
	{
		node * aux = malloc(sizeof(node));
		aux->elem = newElem;

		aux->next = first;				//Coloca el nuevoElem antes de first
		aux->prev = first->prev;		//El anterior del nuevo Elem es el que estaba atras de first

		if(first->prev != NULL)			//Valida si puedo desreferenciar el anterior de first
		{		
			first->prev->next = aux;	//El siguiente al anterior de first ahora es aux
		}
		first->prev = aux;				//El anterior de first ahora es aux
		return 1;
	}

	return addBeforeRec(first->next, elem, newElem);
}	

int 
addAfter(listADT list, listElementT elem, listElementT newElem)
{
	if(addAfterRec(list->first, elem, newElem))
	{
		(list->size)++;

		if(list->last->next != NULL)
		{
			list->last = list->last->next;//Actualiza last, si el newElem es inserto luego de last
		}

		return 1;
	}

	return 0;
}

static int
addAfterRec(node * first, listElementT elem, listElementT newElem)
{
	if(first == NULL)
	{
		return 0;
	}

	int c;
	if((c = compare(first->elem, elem)) == 0)
	{
		node * aux = malloc(sizeof(node));
		aux->elem = newElem;

		aux->next = first->next;	
		aux->prev = first;

		if(first->next != NULL)
		{
			first->next->prev = aux;
		}
		first->next = aux;
		return 1;
	}

	return addAfterRec(first->next, elem, newElem);
}


void 
removeLast(listADT list, listElementT elem)
{
	list->last = removeLastRec(list->last, elem, &(list->size), &(list->first));
	return;
}

static node * 
removeLastRec(node * last, listElementT elem, size_t * size, node ** first)
{
	if(last == NULL)
	{
		return last;
	}

	int c;	
	if((c = compare(last->elem, elem)) == 0)
	{
		if(last->prev != NULL) //Valida en caso que se elimine el primero
		{
			last->prev->next = last->next;
		}
		else //quiere decir que last es el first
		{
			*first = (*first)->next;
		}
		
		if(last->next != NULL) //Valida en caso que elimine el ultimo
		{
			last->next->prev = last->prev;
		}

		node * aux = last->prev;
		free(last);
		(*size)--;
		return aux;
	}

	last->prev = removeLastRec(last->prev, elem, size, first);
	return last;
}