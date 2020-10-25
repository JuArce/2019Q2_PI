#include <stdio.h>
#include "getnum.h"

int
main()
{
    int n, c;
    /*Al salir del ciclo n debe ser un número par mayor que cero*/
    do
    {
        n = getint();
    } while (n <= 0 || n % 2 != 0);

    /*Este ciclo debe incluir la lectura de caracteres y debe ejecutarse
    **mientras no sea fin de archivo y los caracteres sea dígitos o
    **minúsuculas */
   while((c = getchar()) != EOF && ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')))    
}