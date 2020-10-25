#include <stdio.h>

int
main()
{
    int c;
    
    while((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\t') // '\n' no es necesario, pues al salto lo debe hacer de todas formas.
        {
            putchar('\n');
        }
        else
        {
            putchar(c);
        }
    }

    return 0;
}