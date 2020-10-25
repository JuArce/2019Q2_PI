#include <stdio.h>

#define MAXIMO2(a, b, max)  max = ((a) > (b)) ? (a) : (b)

int
main()
{
    int num1, num2, max;

    num1 = 3; num2 = 8;
    MAXIMO2(num1, num2, max);
    printf("Maximo: %d\n", max);
    MAXIMO2(num2, num1, max);
    printf("Maximo: %d\n", max);
}