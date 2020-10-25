#include <stdio.h>
#include <stdlib.h>
#include "listUtil.h"



TList removeIf(TList l, int(* fn)(int));
TList inter(TList l1, TList l2);
int esImpar(int n);


int
main()
{
	/*int v1[] = {1,2,6,3,4,5};
	int v2[] = {6,70,8,9};
	int v3[] = {1,3,5};

	TList l1 = arrayToList(v1, 6);
	TList l2 = arrayToList(v2, 4);
	TList l3 = arrayToList(v3, 3);

	printList(l1);
	printList(l2);
	printList(l3);
	putchar('\n');
	l1 = removeIf(l1, esImpar);
	l2 = removeIf(l2, esImpar);
	l3 = removeIf(l3, esImpar);

	printList(l1);
	printList(l2);
	printList(l3);*/


	int v1[] = {1,2,3,4,5,6,7};
	int v2[] = {2,4,6,8,9};

	TList l1 = arrayToList(v1, 7);
	TList l2 = arrayToList(v2, 5);

	printList(l1);
	printList(l2);

	TList l3 = inter(l1, l2);

	printList(l3);
}



TList 
removeIf(TList l, int(* fn)(int))
{
	if(l == NULL)
	{
		return l;
	}

	if(fn(l->elem))
	{
		TList aux = l;
		l = l->tail;
		free(aux);
		return removeIf(l, fn);
	}

	l->tail = removeIf(l->tail, fn);
	return l;
}

int
esImpar(int n)
{
	return n % 2 == 1;
}


TList
inter(TList l1, TList l2)
{
	if(l1 == NULL || l2 == NULL)
	{
		return NULL;
	}

	if(l1->elem > l2->elem)
	{
		return inter(l1, l2->tail);
	}
	if(l1->elem < l2->elem)
	{
		return inter(l1->tail, l2);
	}

	TList l = malloc(sizeof(TNode));
	l->elem = l1->elem;
	l->tail = inter(l1->tail, l2->tail);
	return l;
}