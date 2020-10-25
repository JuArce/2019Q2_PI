#include <stdio.h>
#include <math.h>
#include "getnum.h"

int lugar(int num, int pos);

int
main()
{
    int boleto, esCapicua = 1;
    int j;

    boleto = getint("Ingrese un numero de 5 dígitos:");

    if(boleto < 10000 || boleto > 99999)
    {
        printf("Ingreso incorrecto de datos\n");
        return 1;
    }

    for(j = 1; j <= 2; j++)
    {
        if(lugar(boleto, j) != lugar(boleto, 5 - j + 1))
        {
            esCapicua = 0;
            break;
        }
    }

    printf("El boleto %ses capicúa\n", (esCapicua) ? "" : "no ");
    return 0;
}

int 
lugar(int num, int pos)
{
    return (num / (int)pow(10, pos - 1)) % 10;
}