#include <stdio.h>
#include <stdlib.h>

#include "multiSetADT.h"

int
main()
{
	multiSetADT s = newMultiSet();

	printf("%d\n", add(s, 10));
	printf("%d\n", add(s, 10));
	printf("%d\n", add(s, 10));
	printf("%d\n", add(s, 20));
	printf("%d\n", add(s, 5));
	printf("%d\n", add(s, 5));
	printf("%d\n", add(s, 10));

	printf("10: %d\n", count(s, 10));
	printf("100: %d\n", count(s, 100));
	printf("5: %d\n", count(s, 5));

	printf("size: %d\t\n", size(s));

	int dim;
	elemType * vec = minElements(s, &dim);

	printf("Dim %d\n", dim);

	for(int i = 0; i < dim; i++)
	{
		printf("%d\t", vec[i]);
	}putchar('\n');

	//removeAll()
}