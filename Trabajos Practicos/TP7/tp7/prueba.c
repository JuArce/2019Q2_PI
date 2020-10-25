#include <stdio.h>
#include "random.h"

#define X 5 //Cantidad de digitos

void generaAleatorio(int incognita[10]);


int
main()
{
    randomize();
}

void
generaAleatorio(int incognita[10])
{
    int numeros[] = {1,2,3,4,5,6,7,8,9};
    int n = 9;
    int digitos = X;
    int aux, rand;

    for(int i = 0; i < digitos; i++)
    {
        rand = randInt(0, n-1);
        incognita[i] = 
        
    }
}