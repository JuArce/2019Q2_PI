#ifndef _moveToFront_h
#define _moveToFront_h

typedef struct moveToFrontCDT * moveToFrontADT;

///*
typedef struct
{
	int code;
	char name[20];
}elemType;

static int
compare(elemType e1, elemType e2)
{
	return e1.code - e2.code;
}
//*/

/*
typedef int elemType;

static int
compare(elemType e1, elemType e2)
{
	return e1 - e2;
}
//*/

moveToFrontADT newMoveToFront();

unsigned int add(moveToFrontADT moveToFront, elemType elem);

unsigned int size(moveToFrontADT moveToFront);

void toBegin(moveToFrontADT moveToFront);

int hasNext(moveToFrontADT moveToFront);

elemType next(moveToFrontADT moveToFront);

elemType * get(moveToFrontADT moveToFront, elemType elem);

#endif