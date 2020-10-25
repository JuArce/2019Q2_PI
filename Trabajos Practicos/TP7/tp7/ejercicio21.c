#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BLOQUE 5

char * strNCpy(char * string, int n);

int
main()
{
    char * string = strNCpy("God save the queen...", 100);
    printf("%s\n", string);
    free(string);
    return 0;
}

char *
strNCpy(char * string, int n)
{
    char * salida;
    int longitud = strlen(string);
    int i;

    if(n > longitud)
    {
        n = longitud;
    }

    salida = malloc((longitud + 1) * sizeof(char));
    if(salida == NULL)
    {
        return NULL;
    }

    for(i = 0; i < n; i++)
    {
        *(salida + i) = *(string + i);
    }

    *(salida + i) = '\0';

    return salida;
}