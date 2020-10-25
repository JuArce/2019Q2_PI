#ifndef __stackADT_h
	#define __stackADT_h

typedef struct stackCDT * stackADT;

typedef int elemType;

stackADT newStack(void);
void freeStack(stackADT stack);
int isEmpty(stackADT stack);
void push(stackADT stack, elemType elem);
elemType pop(stackADT stack);