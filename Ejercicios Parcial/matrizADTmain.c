#include <stdio.h>
#include <stdlib.h>

#include "matrizADT.h"

void 
main()
{
    printf("Que la fuerza este contigo, y no falle la ejecucion\n\n");

    matrixADT matriz = newMatrix();
    printf("Matriz creada\n\n");

    setElement(matriz,2,3,7);
    setElement(matriz,6,1,-5);
    setElement(matriz,4,25,3);
    setElement(matriz,6,15,-3);
    setElement(matriz,6,123,25);


    imprimirElemento(matriz, 2,3);
    imprimirElemento(matriz, 6,1);
    imprimirElemento(matriz, 4,25);
    imprimirElemento(matriz, 6,15);
    imprimirElemento(matriz, 6,123);

    int * max = maxElements(matriz, -15);

    for(int i = 0; i < 6; i++)
    {
        printf("Max: %d\n", max[i]);
    }

    printf("Que la fuerza te acompañe\n");
}