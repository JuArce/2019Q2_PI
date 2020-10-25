#include <stdio.h>

#define EPSILON 0.000001

int factorial(unsigned int n);

int
main()
{
    double euler = 1, anterior;
    
    printf("N\te\n");

    for(int i = 1; euler - anterior > EPSILON; i++)
    {
        printf("%d\t%.10f\n", i, euler);
        anterior = euler;
        euler += 1.0 / (double)factorial(i);
    }
}

int factorial( unsigned int n)
{
    int resultado = 1;
    
    while(n > 1)
    {
        resultado *= n--;
    }

    return resultado;
}