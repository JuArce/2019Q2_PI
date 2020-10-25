#include <stdio.h>

#define PI 3.1415

int 
main()
{
    float a = 0.0, b;
    b = PI + a++;
    printf("%.0f\t%.4f\n", a, b);
    return 0;
}