#ifndef _bagADT_h
#define _bagADT_h

typedef struct bagCDT * bagADT;
typedef int elemType; 

static int 
compare(elemType e1, elemType e2)
{
    return e1 - e2;
}

bagADT newBag();

unsigned int add(bagADT bag, elemType elem);

unsigned int count(const bagADT bag, elemType elem);

unsigned int size(const bagADT bag);

elemType mostPopular(bagADT bag);

#endif