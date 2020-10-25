#include <stdio.h>
#include <string.h>

void invierte(char * origen, char * destino);

int
main()
{
    char origen[] = {"Practica"};
    char destino[20] = {0};
    invierte(origen, destino);
    printf("%s\n", destino);
}

void 
invierte(char * origen, char * destino)
{
    if(*origen == 0)
    {
        return;
    }

    *(destino + strlen(origen) - 1) = *origen;

    invierte(origen + 1, destino);
}