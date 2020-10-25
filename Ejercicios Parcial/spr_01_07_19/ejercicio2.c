#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moveToFrontADT.h"

int
main()
{
	moveToFrontADT p = newMoveToFront();
	elemType aux = {1, "uno"};
	add(p, aux);

	strcpy(aux.name, "dos");
	add(p, aux);

	aux.code = 2;
	add(p, aux);

	aux.code = 3;
	strcpy(aux.name, "tres");
	add(p, aux);

	aux.code = 4;
	strcpy(aux.name, "cuatro");
	add(p, aux);

	printf("%d\n", size(p));

	toBegin(p);
	while(hasNext(p))
	{
		aux = next(p);
		printf("%d %s ", aux.code, aux.name);
	}putchar('\n');

	aux.code = 5;
	elemType * q = get(p, aux);

	aux.code = 3;
	q = get(p, aux);
	printf("%d %s\n", q->code, q->name);

	toBegin(p);
	while(hasNext(p))
	{
		aux = next(p);
		printf("%d %s ", aux.code, aux.name);
	}putchar('\n');
/*
	moveToFrontADT p = newMoveToFront();

	add(p, 1);
	add(p, 2);
	add(p, 3);
	add(p, 4);

	toBegin(p);
	while(hasNext(p))
	{
		printf("%d ", next(p));
	}putchar('\n');

	get(p, 3);

	toBegin(p);
	while(hasNext(p))
	{
		printf("%d ", next(p));
	}putchar('\n');
*/
}