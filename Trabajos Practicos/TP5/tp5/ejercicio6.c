#include <stdio.h>
#include "getnum.h"

#define DELTA 'a' - 'A'

int menu(void);
int aMinuscula(int c);
int aMayuscula(int c);
int caracterSiguiente(int c);
int siguienteLetra(int c);

int 
main()
{
    int c, opcion, respuesta = 0;

    do
    {
        printf("Ingrese un carácter\n");
        c = getchar();

        opcion = menu();

        if(opcion != 0)
        {
            switch(opcion)
            {
                case 1: respuesta = aMinuscula(c); break;
                case 2: respuesta = aMayuscula(c); break;
                case 3: respuesta = caracterSiguiente(c); break;
                case 4: respuesta = siguienteLetra(c); break;
                default: respuesta = 0; 
                        printf("Opción inválida\n"); break;
            }
        }
        
        if(respuesta != 0)
        {   
            printf("%c\n\n", respuesta);
        }
    } while (opcion != 0);
    

    
}

int
menu()
{
    int opcion;
    printf("Seleccione una opción\n");
    printf("0: Salir\n");
    printf("1: Convertir de mayúscula a minúscula\n");
    printf("2: Convertir de minúscula a mayúscula\n");
    printf("3: Imprimir el siguiente carácter\n");
    printf("4: Imprimir siguiente letra (en forma circular)\n");
    opcion = getint("");
    return opcion;  
}

int
aMinuscula(int c)
{
    if(c >= 'A' && c <= 'Z')
    {
        c += DELTA;
    }
    return c;
}

int
aMayuscula(int c)
{
    if(c >= 'a' && c <= 'z')
    {
        c -= DELTA;
    }
    return c;
}

int
caracterSiguiente(int c)
{
    return c + 1;
}

int
siguienteLetra(int c)
{
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return (c == 'z' || c == 'Z') ? (c - ('Z' - 'A')) : (caracterSiguiente(c));
    }
    return c;
}