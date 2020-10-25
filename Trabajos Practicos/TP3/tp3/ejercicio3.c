#include <stdio.h>
#include "getnum.h"

#define MINIMO 300

void
main()
{
    double venta, cobro = MINIMO;
    venta = getdouble("Ingrese la suma vendida en la semana\n");

    if(venta > 1000 && venta <= 2000)
    {
        cobro += venta * 0.05;
    }
    else if(venta > 2000 && venta <= 4000)
    {
        cobro += venta * 0.07;
    }
    else if(venta > 4000)
    {
        cobro += venta * 0.09;
    }

    printf("El monto a cobrar es $%.2f\n", cobro);    
}

