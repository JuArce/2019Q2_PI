#include <stdio.h>

double raizCuadrada(double valorAnterior, int iter, double x);

int
main()
{
    printf("%g\n", raizCuadrada(4, 5, 8));
}

double 
raizCuadrada(double valorAnterior, int iter, double x)
{
    if(iter == 0)
    {
        return valorAnterior;
    }

    valorAnterior = (valorAnterior + x / valorAnterior) / 2;

    return raizCuadrada(valorAnterior, iter - 1, x); 
}