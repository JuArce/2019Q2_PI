#include <stdio.h>

#define MAXIMO2(a, b, max)  max = ((a) > (b)) ? (a) : (b)
#define MAXIMO3(a, b, c, max)  {int aux;\
                                MAXIMO2(a,b, aux);\
                                MAXIMO2(aux, c, max);\
                                }

int
main()
{
    int num1, num2, num3, max;

    num1 = 3; num2 = 8; num3 = 9;
    MAXIMO3(num1, num2, num3, max);
    printf("Maximo: %d\n", max);
    MAXIMO3(num2, num1, num3, max);
    printf("Maximo: %d\n", max);
    MAXIMO3(num2, num3, num1, max);
    printf("Maximo: %d\n", max);
}
