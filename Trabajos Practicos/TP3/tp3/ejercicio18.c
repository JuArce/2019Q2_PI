#include <stdio.h>
#include "getnum.h"

int 
main()
{
    int n;
    int factorial = 1;
    int aux;

    do
    {
        n = getint("Ingrese un entero positivo o cero\n");
        if(n < 0)
        {
            printf("Valor incorrecto. Debe ser positivo o cero\n");
        }
    } while (n < 0);
    
    for(aux = n; aux > 1; aux --)
    {
        factorial *= aux;
    }

    printf("El factorial de %d es: %d\n", n, factorial);
}