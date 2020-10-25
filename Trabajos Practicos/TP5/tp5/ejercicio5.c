#include <stdio.h>

double potencia(double base, int exponente);

int
main()
{
    for(int i = -5; i < 5; i++)
    {
        printf("2^%d = %g\n", i, potencia(2, i));
    }
    printf("%g\n", potencia(0, 0));
    printf("%g\n", potencia(5, 0));

}

double
potencia(double base, int exponente)
{
    double respuesta;
    double auxBase = base;

    if(exponente == 0)
    {
        if(base == 0)
        {
            return -1;
        }
        return 1;
    }

    if(exponente < 0)
    {
        exponente *= -1;
        auxBase = 1.0 / base;
    }

    for(respuesta = 1; exponente > 0; exponente--)
    {
        respuesta *= auxBase;
    }

    return respuesta;
}