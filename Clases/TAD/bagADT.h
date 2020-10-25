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

size_t add(bagADT b, elemType e);

size_t remove(bag ADT b, elemType e);

size_t count(bagADT b, elemType e);

size_t size(bagADT b);

void freeBag(bagADT);

elemType mostPopular(bagADT b);

#endif