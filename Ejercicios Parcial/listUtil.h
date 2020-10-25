typedef struct node * TList;

typedef struct node {
		int elem;
		struct node *tail;
} TNode;

TList arrayToList(int[], int);

void printList(TNode *);
