#include <stdio.h>
#include <stdlib.h>
#include "listUtil.h"

TList elimina(TList l, int(criterio)(int));
int esPar(int n);

int
main()
{
	int vec[] = {1,2,3,4,5,6,7,8,9};
	TList l = arrayToList(vec, 9);
	printList(l);
	elimina(l, esPar);
	printList(l);
}



TList
elimina(TList l, int(criterio)(int))
{
	if(l == NULL)
	{
		return l;
	}

	if(criterio(l->elem))
	{
		TList aux = l;
		l = l->tail;
		free(aux);
	}

	l->tail = elimina(l->tail, criterio);
	return l;
}

int 
esPar(int n)
{
	return n % 2 == 0;
}