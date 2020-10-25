#include "listUtil.h"
#include <stdio.h>

#include <stdlib.h>

TList removeOdd(TList l);

int
main()
{
	int vec[] = {1,2,3,4,5,6,7,8,9};
	TList l = arrayToList(vec, 9);
	printList(l);
	l = removeOdd(l);
	printList(l);
}


TList
removeOdd(TList l)
{
	if(l == NULL || l->tail == NULL)
	{
		return l;
	}

	TList aux = l->tail;
	l->tail = l->tail->tail;
	free(aux);
	l->tail = removeOdd(l->tail);
	return l;

}

