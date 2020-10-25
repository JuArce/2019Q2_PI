#include <stdio.h>
#include "setADT.h"

void printSet(setADT set);

int
main()
{
    setADT s1 = newSet();
    setADT s2 = newSet();
    
    for(int i = 0; i < 20; i++)
    {
        addElem(s1, i * 2);
        addElem(s2, i);
    }

    setADT s3 = unionSet(s1, s2);
    setADT s4 = intersecSet(s1, s2);

    printf("Conjunto 1\n");
    printSet(s1);
    putchar('\n');

    printf("Conjunto 2\n");
    printSet(s2);
    putchar('\n');

    printf("Conjunto 3 Union\n");
    printSet(s3);
    putchar('\n');

    printf("Conjunto 4 Interseccion\n");
    printSet(s4);
    putchar('\n');



}

void
printSet(setADT set)
{
    int dim = getDim(set);
    for(int i = 0; i < dim; i++)
    {
        printf("%d, ", getElem(set, i + 1));
    }putchar('\n');
    return;
}