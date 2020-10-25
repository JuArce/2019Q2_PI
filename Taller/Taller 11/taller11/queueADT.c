#include <stdio.h>
#include <stdlib.h>

#include "queueADT.h"

typedef struct queueCDT
{
	size_t size;
	tNode * first;
	tNode * last;
}queueCDT;

typedef struct tNode
{
	elemType elem;
	tNode * next;
}tNode;

static void freeQueueRec(tNode * first);

queueADT 
newQueue()
{
	return calloc(1, sizeof(queueCDT));
}

void 
freeQueue(queueADT q)
{
	freeQueueRec(q->first);
	free(q);
}

static void
freeQueueRec(tNode * first)
{
	if(first == NULL)
	{
		return;
	}
	freeQueueRec(first->next);
	free(first);
	return;
}

int 
queue(queueADT q, elemType elem)
{
	tNode * aux = malloc(1 * sizeof(tNode));

	if(aux == NULL)
	{
		return 0; //Falla la asignacion
	}

	aux->elem = elem;

	if(q->size == 0)
	{
		q->first = aux;
	}

	q->last->next = aux;
	q->last = aux;
	(q->size)++;

	return 1;
}

int 
dequeue(queueADT q, elemType * elem)
{
	if(q->first == NULL)
	{
		return 0; //No puede sacar elementos
	}

	*elem = q->first->elem;

	tNode * aux = q->first;
	if(q->first == q->last) //o tambie si q->size == 1
	{
		q->first = NULL;
		q->last = NULL;
	}
	else
	{
		q->first = q->first->next;
	}

	(q->size)--;	
	free(aux);
	return 1;
}

void 
imEmpty(queueADT q)
{
	return q->size == 0;
}
