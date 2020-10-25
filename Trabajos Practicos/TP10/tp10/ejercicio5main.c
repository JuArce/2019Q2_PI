#include <stdio.h>
#include "complexADT.h"

int
main()
{
    complexADT z1 = newComplex(1,2);
    complexADT z2 = newComplex(2,4);

    printf("Z1\nParte real: %g\tParte imaginaria: %g\nModulo: %g\tArgumento: %g\n",
            getRe(z1), getIm(z1), getMod(z1), getArg(z1));
    printf("Z2\nParte real: %g\tParte imaginaria: %g\nModulo: %g\tArgumento: %g\n",
            getRe(z2), getIm(z2), getMod(z2), getArg(z2));
    
    complexADT z3 = sum(z1, z2);
    complexADT z4 = prod(z1, z2);

    printf("Z1 + Z2: %g + %gi\n", getRe(z3), getIm(z3));
    printf("Z1 * Z2: %g + %gi\n", getRe(z4), getIm(z4));

    changeRe(z1, 5);
    printf("Z1\nParte real: %g\tParte imaginaria: %g\nModulo: %g\tArgumento: %g\n",
            getRe(z1), getIm(z1), getMod(z1), getArg(z1));

    freeComplex(z1);
    freeComplex(z2);
    freeComplex(z3);
    freeComplex(z4);
    return 0;
}