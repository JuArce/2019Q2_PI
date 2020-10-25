#ifndef _listADT_h
#define _listADT_h

typedef struct listCDT * listADT;
typedef int elemType;

listADT newList();

void freeList(listADT l);

void add(listADT l, elemType elem);

int removeElem(listADT l, elemType elem);

int contains(const listADT l, elemType elem);

size_t size(const listADT l);

int isEmpty(const listADT l);

void toBegin(listADT l);

elemType next(listADT l);

int hasNext(listADT l);

listADT map(const listADT l, elemType(*fn)(elemType elem));

elemType reduce(listADT l, elemType init, elemType(*fn)(elemType e1, elemType e2));

static int 
compare(elemType e1, elemType e2)
{
    return e1 - e2;
}

#endif