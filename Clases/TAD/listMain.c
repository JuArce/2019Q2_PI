#include <stdio.h>

#include "listADT.h"

elemType duplicate(elemType elem);
elemType suma(elemType e1, elemType e2);
void printList(listADT l);

int
main()
{
	listADT l = newList();
	add(l, 20);
	add(l, 30);
	add(l, 10);

	for(int i = 0; i < 100; i++)
	{
		add(l, i);
		printf("Elemento agregado %d\n", i);
	}

	printf("Lista 1:\n");
	printList(l);

	listADT l2 = map(l, duplicate);

	printf("Lista Duplicada:\n");
	printList(l2);

	printf("Reduce: %d\n", reduce(l, 0,  suma));

}

elemType 
duplicate(elemType elem)
{
	return 2 * elem;
}

void
printList(listADT l)
{
	toBegin(l);
	while(hasNext(l))
	{
		printf("%d, ", next(l));
	}putchar('\n');
}

elemType 
suma(elemType e1, elemType e2)
{
	return e1 + e2;
}