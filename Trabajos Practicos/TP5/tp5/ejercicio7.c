#include <stdio.h>
#include <math.h>

#define EPSILON 0.00001

double exponencial(double x);

int
main()
{
    double num = exponencial(2);
    double num2 = exp(2);
    printf("%g\t%g\n", num, num2);
}

double 
exponencial(double x)
{
    double resultado = 1;
    double anterior = 0;
    double potencia = 1, factorial = 1;
    int n = 1;

    while(resultado - anterior > EPSILON)
    {
        anterior = resultado;
        potencia *= x;
        factorial *= n++;
        resultado += potencia / factorial;
    }

    return resultado;
}
