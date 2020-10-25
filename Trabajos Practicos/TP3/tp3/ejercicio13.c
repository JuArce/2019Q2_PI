#include <stdio.h>
#include "getnum.h"

int
main()
{
    int n;
    do
    {
        n = getint("Ingrese el lado del cuadrado\n");
    } while (n < 1);
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            putchar('*');
        }
        putchar('\n');
    }

    putchar('\n');

    for(int i = 1; i <= n*n; i++)
    {
        putchar('*');
        if(i % n == 0)
        {
            putchar('\n');
        }
    }
}