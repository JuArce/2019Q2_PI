#include <stdio.h>

#define CUBO(x) (x) * (x) * (x)

int cubo(int num);

int
main()
{
    int a = 3, b, c, d, e, f;

    b = CUBO(a+1);
    c = CUBO(a);
    a += 1;
    d = 3;
    e = cubo(++d);
    f = cubo(d++);

    printf("%d\t%d\t%d\t%d\t%d\t%d\n", a, b, c, d, e, f);
    return 0;
}

int
cubo(int num)
{
    return num * num* num;
}