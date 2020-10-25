#include <stdio.h>

int max(int a, int b, int c);

int
main()
{
    int num1 = 2, num2 = 4, num3 = 9;
    printf("%d\n", max(num1, num2, num3));
    printf("%d\n", max(num1, num3, num2));
    printf("%d\n", max(num2, num1, num3));
    printf("%d\n", max(num2, num3, num1));
    printf("%d\n", max(num3, num1, num2));
    printf("%d\n", max(num3, num2, num1));
}

int
max(int a, int b, int c)
{
    return  (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}
