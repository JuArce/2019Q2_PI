#include <stdio.h>

void
main()
{
    int a, b;
    a = getchar();
    b = getchar();
    if(a == b)
    {
        printf("Los carácteres '%c' y '%c' son iguales\n", a, b);
    }
    else if(a > b)
    {
        printf("El carácter '%c' es mayor a '%c'\n", a, b);
    }
    else
    {
        printf("El carácter '%c' es menor a '%c'\n", a, b);
    }
}
