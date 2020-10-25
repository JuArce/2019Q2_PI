#include <stdio.h>
#include "getnum.h"

int
main()
{
    int numero;
    int bitsUno = 0;
    
    do
    {
        numero = getint("Ingrese un entero positivo\n");
    } while(numero < 0);

    for(int aux = numero; aux > 0; aux /= 2)
    {
        if(aux % 2)
        {
            bitsUno++;
        }
    }

    printf("El número %d posee %d bit%s en uno\n", numero, bitsUno, (bitsUno == 1)? "" : "s");
    return 0;
}