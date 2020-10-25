#include <stdio.h>

#define DIGITO 5
#define TRUE 1

int
main()
{
    int c;
    int cantidadEntera = 0, cantidadDecimal = 0;
    int huboPunto = 0;
    int negativo = 0;

    printf("Ingrese un número real\n");

    while(((c = getchar()) >= '0' && c <= '9') || (c == '.' && !huboPunto) || (c == '-' && !negativo))
    {
        if(c == '.')
        {
            huboPunto = TRUE;
        }
        
        if(c == '-')
        {
            negativo = TRUE;
        }

        if(c == (DIGITO + '0'))
        {
            if(huboPunto)
            {
              cantidadDecimal++;
            }
            else
            {
                cantidadEntera++;
            }
        }

    }

    printf("Cantidad de '%d' en parte entera: %d\nCantidad de '%d' en parte decimal: %d\n"
            , DIGITO, cantidadEntera, DIGITO, cantidadDecimal);
}