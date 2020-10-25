#include <stdio.h>
#include <math.h>
#include "getnum.h"

#define MAX 99999
#define MIN 10000

int lugar(int num, int pos);

int
main()
{
    int boleto, esCapicua = 1;
    int j;

    do
    {
        boleto = getint("Ingrese un número de 5 dígitos: ");
        if(boleto < MIN || boleto > MAX)
        {
            printf("Ingreso incorrecto de datos\n");
        }
    } while (boleto < MIN || boleto > MAX);
    

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