#include <stdio.h>
#include "getnum.h"

#define DIGITO 5

int 
main()
{
    int n = getint("Ingrese un entero\n");
    int cantidad = 0; //Cantidad de DIGITO que tiene el numero
    int aux;
    
    if(n < 0)
    {
       n *= -1; 
    }

    for(aux = n; aux > 0; aux /= 10)
    {
        if((aux % 10) == DIGITO)
        {
            cantidad++;
        }
    }

    printf("Cantidad de '%d': %d\n", DIGITO, cantidad);
}