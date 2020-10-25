#include <stdio.h>
#include "getnum.h"

void
main()
{
	float velocidad = getfloat("Ingrese una velocidad en m/s\n");
	printf("Velocidad = %.2f m/s\t=%.2f Km/h\n", velocidad, velocidad * 3.6);
}