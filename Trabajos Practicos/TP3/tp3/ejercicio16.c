#include <stdio.h>
#include "getnum.h"

#define BASE 2 //Base a la que se quiere convertir el número base 10
#define MAX 1023 //Por limitación del tipo int equivale a 1 111 111 111
int
main()
{
    int decimal, binario = 0;
    int aux, potencia = 1;

    do
    {
        decimal = getint("Ingrese un entero positivo (entre 0 y %d)\n", MAX);
        if(decimal < 0 || decimal > 1023)
        {
            printf("Número fuera de rango\n");
        }
    }while(decimal < 0 || decimal > 1023);

    for(aux = decimal; aux > 0; aux /= BASE, potencia *= 10)
    {
        binario += potencia * (aux % 2);
    }

    printf("Decimal : %d\tBinario: %d\n", decimal, binario);
}