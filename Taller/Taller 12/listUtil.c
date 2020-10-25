#include <stdio.h>
#include <stdlib.h>
#include "listUtil.h"

TList
arrayToList(int elements[], int dim) {
	TList nodes[dim];
	for(int i = dim - 1; i >= 0; i--) {
		nodes[i] = calloc(1,sizeof(*(nodes[i])));
		nodes[i]->elem = elements[i];
		if(i != dim - 1) {
			nodes[i]->tail = nodes[i+1];
		}
	}
	return nodes[0];
}

void 
printList(TNode * list) {
	if(list == NULL) {
		printf("NULL\n");
		return ;
	}
	printf("%d -> ", list->elem);
	printList(list->tail);
}
