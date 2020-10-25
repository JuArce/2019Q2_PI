#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define DIVISOR(a, b)   ((a) % (b) == 0) ? TRUE : FALSE

int
main()
{
    int a, b = 10, c = 3;
    a = DIVISOR(b, c);
    printf("%d\n", a);
    a = DIVISOR(b, c-1);
    printf("%d\n", a);
}