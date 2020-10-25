#include <stdio.h>
#include "getnum.h"

int
main()
{
	unsigned int segundos = getint("Ingrese un intervalo de tiempo expresado en segundos\n");
	printf("%d seg equivale a %d horas, %d minutos, %d segundos\n", 
		segundos, segundos / 3600, (segundos % 3600) / 60, segundos % 60);
}