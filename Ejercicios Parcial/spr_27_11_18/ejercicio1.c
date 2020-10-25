
#include <stdio.h>
#include <stdlib.h>
#include "listUtil.h"

TList 
listaAscendente(TList l)
{
	if(l == NULL || l->tail == NULL)
	{
		return l;
	}

	if(l->tail->elem <= l->elem)
	{
		TList aux = l->tail;
		l->tail = l->tail->tail;
		free(aux);
		l = listaAscendente(l);
		return l;
	}

	l->tail = listaAscendente(l->tail);
	return l;
}

int 
main()
{
	int v1[] = {1,1,3,2,4,5,6,10,1};
	int v2[] = {1,3,4,5,6,8,9};
	int v3[] = {12,1,2,3,4,5};

	TList l1 = arrayToList(v1, 9);
	TList l2 = arrayToList(v2, 7);
	TList l3 = arrayToList(v3, 6);

	printf("Antes\n");
	printList(l1);
	putchar('\n');
	printList(l2);
	putchar('\n');
	printList(l3);
	putchar('\n');

	l1 = listaAscendente(l1);
	l2 = listaAscendente(l2);
	l3 = listaAscendente(l3);

	printf("Despues\n");
	printList(l1);
	putchar('\n');
	printList(l2);
	putchar('\n');
	printList(l3);
	putchar('\n');

}