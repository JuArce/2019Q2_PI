#ifndef _listADT_h
#define _listADT_h

typedef struct listCDT * listADT;
typedef int elemType;

static int
compare(elemType e1, elemType e2)
{
	return e1 - e2;
}

listADT newList();

void add(listADT list, elemType elem);

void removeE(listADT list, elemType elem);

void toBegin(listADT list);

int hasNext(listADT list);

elemType next(listADT list);

void toBeginAsc(listADT list);

int hasNextAsc(listADT list);

elemType nextAsc(listADT list);

#endif