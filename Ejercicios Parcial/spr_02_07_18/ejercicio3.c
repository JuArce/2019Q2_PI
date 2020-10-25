#include <stdio.h>
#include <stdlib.h>
#include "listADT.h"

void printList(listADT l); 

int 
main()
{
	listADT l = newList();
	printf("\nLista creada\n");

	printf("\nAñadiendo elementos...\n");
	for(int i = 0; i <= 10; i++)
	{
		insert(l, i * 10);
	}
	printf("\nElementos añadidos\n");
	printf("\nSIZE: %d", size(l));


	printList(l);

	printf("\nPrueba addBefore\n");
	for(int i = 0; i < 100; i+=5)
	{
		addBefore(l, i+5 ,i);
	}

	printf("\nPrueba addAfter\n");
	for(int i = 0; i <= 10; i++)
	{
		addAfter(l, i * 10, i * 10 + 1);
	}

	printf("\nSIZE: %d", size(l));
	printList(l);


	printf("\nPrueba removeLast\n");
	removeLast(l, 0);
	removeLast(l, 101);
	removeLast(l, 21);


	printf("\nSIZE: %d", size(l));
	printList(l);

	printf("\nEjecución terminada\n");

	freeList(l);
}

void
printList(listADT l)
{
	toBegin(l);
		printf("\nImprimiendo elementos...\n");
	while(hasNext(l))
	{
		printf("%d -> ", next(l));
	}printf("NULL\n");
	return;
}