#include <stdio.h>

int dcm(int a, int b);

int
main()
{
    printf("%d\t%d:\t%d\n", 225, 146, dcm(225, 146));
    printf("%d\t%d:\t%d\n", 226, 146, dcm(146, 226));
}

int
dcm(int a, int b)
{
    int aux = a;
    while(aux > 0)
    {
        a = b;
        b = aux;
        aux = a % b;
    }

    return b;
}