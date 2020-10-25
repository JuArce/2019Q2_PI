#include <stdio.h>
#include <stdlib.h>

typedef struct node * tList;

typedef struct node
{
	int elem;
	struct node * tail;
}node;


tList 
removeRepeated(tList l)
{
	if(l == NULL || l->tail == NULL)
	{
		return l;
	}

	if(l->elem == l->tail->elem)
	{
		tList aux = l->tail;
		l->tail = l->tail->tail;
		free(aux);
		return removeRepeated(l);
	}

	l->tail = removeRepeated(l->tail);
	return l;
}

int
main()
{
	tList node4 = malloc(sizeof(struct node));
	node4->elem = 4;
	node4->tail = NULL;

	tList node3 = malloc(sizeof(struct node));
	node3->elem = 3;
	node3->tail = node4;

	tList node2 = malloc(sizeof(struct node));
	node2->elem = 3;
	node2->tail = node3;

	tList node1 = malloc(sizeof(struct node));
	node1->elem = 1;
	node->tail = node2;

	tList aux = removeRepeated(node1);

	tList current = aux;

	while(current != NULL)
	{
		printf("%d,  ", current->elem);
		current = current->tail;
	}putchar('\n');
}