#include <stdio.h>
#include <stdlib.h>
#include "listADT.h"

int main()
{
	listADT l = newList();
	add(l ,3);
	add(l, 1);
	add(l, 5);
	add(l, 2);

	toBegin(l);
	toBeginAsc(l);

	while(hasNext(l))
	{
		printf("%d -> ", next(l));
	}printf("NULL\n");

	while(hasNextAsc(l))
	{
		printf("%d -> ", nextAsc(l));
	}printf("NULL\n");
}
