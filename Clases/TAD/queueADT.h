#ifndef _queueTAD_h
	#define _queueTAD_h

typedef struct queueCDT * queueADT;

typedef int elemType;

queueADT newQueue();
void freeQueue(queueADT q);
int queue(queueADT q, elemType elem);
int dequeue(queueADT q, elemType * elem);
void imEmpty(queueADT q);
void toBegin(queueADT q);
int hasNext(queueADT q);
elemType next(queueADT q);

#endif