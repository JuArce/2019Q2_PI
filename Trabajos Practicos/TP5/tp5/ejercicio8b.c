#include <stdio.h>
#include <math.h>
#include "getnum.h"

#define ENTERO 0
#define DECIMA 1
#define CENTESIMA 2
#define MILESIMA 3

double redondeo(double num, int cifras);
int menu(void);

int
main()
{
    double numero, respuesta;
    int opcion, imprimir;

    do
    {
        numero = getdouble("Ingrese un número real\n");
        opcion = menu();
        imprimir = 1; //Flag para imprimir la salida o no
        if(opcion != 0)
        {
            switch(opcion)
            {
                case 1: respuesta = redondeo(numero, ENTERO); break;
                case 2: respuesta = redondeo(numero, DECIMA); break;
                case 3: respuesta = redondeo(numero, CENTESIMA); break;
                case 4: respuesta = redondeo(numero, MILESIMA); break;
                default:
                        printf("Opción inválida\n");
                        imprimir = 0; break;
            }
            if(imprimir != 0)
            {
                printf("%g\t%g\n", numero, respuesta);
            }
        }
    } while (opcion != 0);
     
}

int menu(void)
{
    printf("1: Redondeo al entero más cercano\n");
    printf("2: Redondeo a la décima más cercana\n");
    printf("3: Redondeo a la centésima más cercana\n");
    printf("4: Redondeo a la milésima más cercana\n");
    printf("0: Salir\n");
    int opcion = getint("Seleccione una opción\n");
    return opcion;
}

double
redondeo(double num, int cifras)
{
    int factor = (int)pow(10, cifras);
    return floor(num * factor + 0.5) / factor;
}