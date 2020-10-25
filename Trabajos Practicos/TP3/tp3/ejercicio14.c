#include <stdio.h>
#include <ctype.h>

#define MAYUSCULA 1
#define MINUSCULA 0

int 
main()
{
    int c;
    int cantMayusculas = 0, cantMinusculas = 0;
    int menor = 'Z';

    while((c = getchar()) && (isalpha(c) || c == ' ')) //    while(isalpha(c = getchar()) || c == ' ') tambien funciona
    {
        if(c != ' ')
        {
            if(toupper(c) < toupper(menor))
            {
                menor = c;
            }

            if(isupper(c))
            {
                cantMayusculas++;
            }
            else
            {
                cantMinusculas++;
            }
        }
    }

    if(cantMayusculas + cantMinusculas > 0)
    {
        printf("El menor alfabéticamente es '%c'\nCantidad de mayúsculas: %d\nCantidad de minúsculas: %d\n",
                menor, cantMayusculas, cantMinusculas);
    }
    else
    {
        printf("No se ingresaron caracteres\n");
    }
}