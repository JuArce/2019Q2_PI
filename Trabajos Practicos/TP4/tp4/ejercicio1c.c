#include <stdio.h>

#define CUBO(x) (x) * (x) * (x)

int cubo(int num);

int
main()
{
    int a = 4, b, c;

    b = CUBO(a + 1);
    c = cubo(a + 1);

    printf("%d\t%d\n", b, c);
}

int
cubo(int num)
{
    return num * num * num;
}