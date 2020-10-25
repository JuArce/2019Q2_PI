#include <stdio.h>
#include <stdlib.h>
#include "bagADT.h"


typedef struct node 
{
    elemType elem;
    size_t count;
    struct node * tail;
}node;

typedef struct bagCDT
{
    size_t size;
    node * first;
}bagCDT;


static node * addRec(node * first, elemType elem, size_t * size, size_t * count);
static unsigned int countRec(node * first, elemType elem);
static void mostPopularRec(node * first, elemType * popular, size_t * popularCount);


bagADT 
newBag()
{
    return calloc(1, sizeof(bagCDT));
}

unsigned int 
add(bagADT bag, elemType elem)
{
    size_t auxCount;
    bag->first = addRec(bag->first, elem, &(bag->size), &auxCount);
    return auxCount;
}

static node *
addRec(node * first, elemType elem, size_t * size, size_t * count)
{
    int c;
    if(first == NULL || (c = compare(first->elem, elem)) > 0)
    {
        node * aux = calloc(1, sizeof(node));
        aux->elem = elem;
        (aux->count)++;
        (*size)++; 
        *count = aux->count;
        aux->tail = first;
        return aux;
    }

    if(c == 0)
    {
        (first->count)++;
        *count = first->count;
        return first;
    }

    first->tail = addRec(first->tail, elem, size, count);
    return first;
}

unsigned int 
count(const bagADT bag, elemType elem)
{
    return countRec(bag->first, elem);
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
        return first->count;
    }
    return countRec(first->tail, elem);
}

unsigned int 
size(const bagADT bag)
{
    return bag->size;
}

elemType 
mostPopular(bagADT bag)
{
    if(bag->size == 0)
    {
        exit(1);
    }

    elemType popular = bag->first->elem;
    size_t popularCount = bag->first->count;
    mostPopularRec(bag->first->tail, &popular, &popularCount);
    return popular;

}

static void
mostPopularRec(node * first, elemType * popular, size_t * popularCount)
{
    if(first == NULL)
    {
        return;
    }

    if(first->count > *popularCount)
    {
        *popular = first->elem;
        *popularCount = first->count;
    }
    mostPopularRec(first->tail, popular, popularCount);
    return;
}