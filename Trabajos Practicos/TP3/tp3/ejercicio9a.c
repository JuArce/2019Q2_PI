/*Programa que cuenta espacios en blanco, tabulaciones y nuevas líneas */
#include <stdio.h>

int
main()
{
    int blancos = 0, tabs = 0, saltos = 0;
    int c;
    while((c = getchar()) != EOF)
    {
        switch(c)
        {
            case ' ': blancos++; break;
            case '\t': tabs++; break;
            case '\n': saltos++; break;
        }
    }

    printf("\nEspacios blancos:%5d\nTabulaciones:%9d\nSaltos de línea:%6d\n", blancos, tabs, saltos);
    return 0;
}