#include <stdio.h>
#include <stdlib.h>
#include "calADT.h"


typedef struct node
{
	tEvent event;
	struct node * next;
}node;

typedef struct calCDT
{
	size_t size;
	node * first;
	node * iter;
}calCDT;


static node * addEventRec(node * first, tEvent event, size_t * size);
static int compare(tDate e1, tDate e2);


calADT newCal()
{
	return calloc(1, sizeof(calCDT));
}

int addEvent(calADT cal, tEvent event)
{
	size_t auxSize = cal->size;
	cal->first = addEventRec(cal->first, event, &(cal->size));
	if(auxSize < cal->size)
	{
		return 1;
	}
	return 0;
}

static node * 
addEventRec(node * first, tEvent event, size_t * size)
{
	int c;
	if(first == NULL || (c = compare(first->event.date, event.date)) > 0)
	{
		node * aux = malloc(sizeof(node));
		aux->event = event;
		aux->next = first;
		(*size)++;
		return aux;
	}

	if(c == 0)
	{
		return first;
	}

	first->next = addEventRec(first->next, event, size);
	return first;
}

static int
compare(tDate e1, tDate e2)
{
	int f1 = (int)e1.day + (int)e1.month * 100 + (int)e1.year * 10000;
	int f2 = (int)e2.day + (int)e2.month * 100 + (int)e2.year * 10000;
	return f1 - f2;
}


void toBegin(calADT cal)
{
	cal->iter = cal->first;
	return;
}

int hasNext(calADT cal)
{
	return cal->iter != NULL;
}

tEvent nextElement(calADT cal)
{
	tEvent aux = cal->iter->event;
	cal->iter = cal->iter->next;
	return aux;
}