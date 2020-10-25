#ifndef _listADT_h
#define _listADT_h

typedef struct listCDT * listADT;

typedef int listElementT;

static int 
compare(listElementT e1, listElementT e2)
{
    return e1 - e2;
}

listADT newList();
int insert(listADT list, listElementT elem);
int size(listADT list);
void toBegin(listADT list);
int hasNext(listADT list);
listElementT next(listADT list);
void freeList(listADT l);

int addBefore(listADT list, listElementT elem, listElementT newElem);

int addAfter(listADT list, listElementT elem, listElementT newElem);

void removeLast(listADT list, listElementT elem);

#endif
