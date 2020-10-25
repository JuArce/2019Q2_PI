#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define isdigit(c)  ((c) >= '0' && (c) <= '9') ? TRUE : FALSE

int
main()
{
    int letra;
    letra = getchar();
    if(isdigit(letra))
    {
        printf("Es un dígito\n");
    }
}