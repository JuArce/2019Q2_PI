#include <stdio.h>
#include <math.h>
#include "getnum.h"

#define TRUE 1
#define FALSE 0

int esCapicua(int num);

int
main()
{
    int boleto, capicua;

    do
    {
        boleto = getint("Ingrese un numero de boleto: ");

        if(boleto < 0)
        {
            printf("Ingreso incorrecto de datos\n");
        }
    } while (boleto < 0);
    
    capicua = esCapicua(boleto);

    printf("El boleto %ses capicúa\n", (capicua) ? "" : "no ");
    return capicua;
}

int
esCapicua(int num)
{
    int aux = num;
    int invertido = 0;

    while(aux > 0)
    {
        invertido = 10 * invertido + (aux % 10);
        aux /= 10;
    }
    return (invertido == num) ? TRUE : FALSE;
}
