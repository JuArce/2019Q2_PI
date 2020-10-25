#include <stdio.h>
#include "getnum.h"

#define TRUE 1
#define FALSE 0
#define BASE 2 //Con esto, el programa puede pasar de cualquier sistema a base 10. Solo cambiar el valor de BASE.
//Adaptado a base 2. Cambiar frontend de acuerdo a la base
int
main()
{
    int decimal = 0, binario;
    int aux, resto, potencia = 1, numOk = TRUE;

    binario = getint("Ingrese un número positivo en base 2\n");
    
    for(aux = binario; numOk && aux > 0; aux /= 10, potencia *= BASE)
    {
        resto = aux % 10;
        if(resto > BASE - 1)
        {
            numOk = FALSE;
        }
        else
        {
            decimal += resto * potencia;            
        } 
    }

    (numOk) ? printf("Binario: %d\tDecimal: %d\n", binario, decimal) : printf("El número ingresado es incorrecto\n");
}