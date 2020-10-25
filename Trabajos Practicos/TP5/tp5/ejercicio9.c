#include <stdio.h>
#include <math.h>

#define PASO 0.001
#define MIN 0
#define MAX 10
#define EPSILON 0.00000001
#define POSITIVO 1
#define NEGATIVO -1

double funcion(double n);

int
main()
{
    double imagen;
    int signo, signoAnt;

    for(double i = MIN; i <= MAX; i += PASO)
    {
        imagen = funcion(i);
        signo = (imagen > 0) ? POSITIVO : NEGATIVO;

        if(signo != signoAnt)
        {
            printf("Raiz (Bolzano): %g\n", i);
        }

        if(fabs(imagen) < EPSILON)
        {
            printf("Raiz (Cero): %g\n", i);
        }
        signoAnt = signo;
    }
}

double 
funcion(double n)
{
    return sin(n) + log(n);
}
