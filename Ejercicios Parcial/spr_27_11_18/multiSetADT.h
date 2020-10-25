#ifndef _multiSetADT_h
#define _multiSetADT_h

typedef struct multiSetCDT * multiSetADT;

typedef int elemType;

static int
compare(elemType e1, elemType e2)
{
	return e1 - e2;
}

multiSetADT newMultiSet();

unsigned int add(multiSetADT multiSet, elemType elem);

unsigned int count(const multiSetADT multiSet, elemType elem);

unsigned int size(const multiSetADT multiSet);

int removeElem(multiSetADT multiSet, elemType elem);

void removeAll(multiSetADT multiSet, elemType elem);

elemType * minElements(const multiSetADT multiSet, int * dim);

#endif