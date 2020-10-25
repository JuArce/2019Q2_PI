#include <stdio.h>
#include <math.h>

double redondeo(double num, int cifras);

int
main()
{
    printf("%g\n", redondeo(15.238523, 2));
}

double
redondeo(double num, int cifras)
{
    int factor = (int)pow(10, cifras);
    return floor(num * factor + 0.5) / factor;
}