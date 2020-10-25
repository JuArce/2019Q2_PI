#include <stdio.h>
#include "getnum.h"

int absoluto(int n);

int 
main()
{
    int numero;
    int aux, invertido = 0;
    
    numero = getint("ingrese un número entero\n");

    aux = absoluto(numero);
    
    while(aux > 0)
    {
        invertido = 10 * invertido + (aux % 10); 
        aux /= 10;
    }
    
    printf("El número %d %ses capicua\n", numero, (absoluto(numero) == invertido)? "" : "no ");
}

int absoluto(int n)
{
    return (n > 0) ? n : -n;
}