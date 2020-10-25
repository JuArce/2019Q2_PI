#include <stdio.h>

#define EPSILON 0.00001

int
main()
{
    double y;

    for(y = 0; y - 1.0 > EPSILON || 1.0 - y > EPSILON; y += 0.1)
    {
        printf("%f\n", y);
    }
}