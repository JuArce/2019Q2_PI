#include <stdio.h>

int
main()
{
    int c, mayor = 0;

    while((c = getchar()) != EOF)
    {
        if(c > mayor)
        {
            mayor = c;
        }
    }
    printf("El mayor es %c\n", c);
}