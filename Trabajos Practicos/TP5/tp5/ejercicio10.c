#include <stdio.h>
#include <math.h>
#include "getnum.h"

int menu(void);
int MCD(int a, int b);
void simplificarFraccion(int numerador, int denominador);
void sumarFracciones(int num1, int denom1, int num2, int denom2);

int
main()
{
    int opcion;
    
    do
    {
        opcion = menu();

        switch(opcion)
        {
            case 1: 
            {
                int num = getint("Ingrese el numerador\n");
                int denom = getint("Ingrese el denominador\n");
                simplificarFraccion(num, denom);
                break;
            }

            case 2: 
            {
                int num1 = getint("Ingrese el numerador de la primer fracción\n");
                int denom1 = getint("Ingrese el denominador de la primer fracción\n");
                int num2 = getint("Ingrese el numerador de la segunda fracción\n");
                int denom2 = getint("Ingrese el denominador de la segunda fracción\n");
                sumarFracciones(num1, denom1, num2, denom2);
                break;
            }

            default:
            {
                printf("Opción inválida\n");
            }
        }
    }while(opcion != 0);
}

int
menu(void)
{
    int opcion;

    printf("1: Simplificar fracción\n");
    printf("2: Sumar dos fracciones\n");
    printf("0: Finalizar ejecución");

    opcion = getint("\nSeleccione una opcion\n");
    return opcion;
}

int 
MCD(int a, int b)
{
    int resto = a;

    while(resto > 0)
    {
        a = b;
        b = resto;
        resto = a % b;
    }

    return b;
}

void
simplificarFraccion(int numerador, int denominador)
{
    int maxComDiv = MCD(fabs(numerador), fabs(denominador));
    int signo = (numerador < 0 || denominador < 0) ? '-' : ' ';

    printf("%c%d", signo, (int)fabs(numerador/maxComDiv));

    if(fabs(denominador) / maxComDiv != 1)
    {
        printf("/%d\n", (int)fabs(denominador/maxComDiv));
    }
    else
    {
        putchar('\n');
    }  
}

void
sumarFracciones(int num1, int denom1, int num2, int denom2)
{
    int numSuma, denomSuma;

    denomSuma = (int)fabs(denom1) * (int)fabs(denom2);
    numSuma = num1 * denom2 + num2 * denom1;

    simplificarFraccion(numSuma, denomSuma);
}