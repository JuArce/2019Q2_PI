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
static int containsRec(node * first, elemType elem);
static node * mapRec(node * first, elemType(*fn)(elemType elem));
static elemType reduceRec(node * first, elemType init, elemType(*fn)(elemType e1, elemType e2));
static elemType getRec(node * first, size_t index);

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
    return;
}

static node *
addRec(node * first, elemType elem, size_t * size)
{
    int c;
    if(first == NULL || (c = compare(first->elem, elem)) > 0) //>0 significa que el elem debe ir antes de first
    {
        node * aux = malloc(sizeof(node));
        aux->elem = elem;
        aux->tail = first;
        (*size)++;
        return aux;
    }

    if(c == 0) //Ya existe el elemento
    {
        return first;
    }

    first->tail = addRec(first->tail, elem, size);
    return first;
}

int 
removeElem(listADT l, elemType elem)
{
    size_t auxSize = l->size;

    l->first = removeRec(l->first, elem, &(l->size));

    return (l->size != auxSize);
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
        (*size)--;
        free(first);
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
containsRec(node * first, elemType elem)
{
    int c;
    if(first == NULL || (c = compare(first->elem, elem)) > 0)
    {
        return 0;
    }

    if(c== 0)
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

void 
toBegin(listADT l)
{
    l->iter = l->first;
    return;
}

elemType 
next(listADT l) //Devuelve el elemento del iter, y avanza el iter al siguiente nodo de la lista
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
    listADT nL = newList(); //Nueva lista
    nL->size = l->size;
    nL->first = mapRec(l->first, fn);
    return nL;
}

static node *
mapRec(node * first, elemType(*fn)(elemType elem))
{
    if(first == NULL)
    {
        return first;
    }

    node * aux = malloc(sizeof(node));
    aux->elem = fn(first->elem);
    aux->tail = mapRec(first->tail, fn);
    return aux;
} 

elemType 
reduce(listADT l, elemType init, elemType(*fn)(elemType e1, elemType e2))
{
    return reduceRec(l->first, init, fn);
}

static elemType
reduceRec(node * first, elemType init, elemType(*fn)(elemType e1, elemType e2))
{
    if(first == NULL)
    {
        return init;
    }

    init = fn(first->elem, reduceRec(first->tail, init, fn));
    return init;
} 

elemType
get(listADT l, size_t index)
{
    if(index >= l->size)
    {
        exit(1);
    }
    return getRec(l->first, index);
}

static elemType
getRec(node * first, size_t index)
{
    if(index == 0)
    {
        return first->elem;
    }

    return getRec(first->tail, index - 1);
}