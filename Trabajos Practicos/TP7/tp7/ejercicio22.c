#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOQUE 5
#define MAX_ALUMNOS 2000
#define MAX_NOMBRE 50

typedef char  tAlumnos[MAX_ALUMNOS][MAX_NOMBRE];
 
char ** alumnosAprobados(tAlumnos alumnos, int notas[]);
void liberarMemoria(char ** arreglo);

int 
main()
{
    tAlumnos alumnos = {"Fernanda", "Ariel", "Fernando", "Francisco", "Sergio", "Candelaria","Fernanda", "Ariel", "Fernando", "Francisco", "Sergio", "Candelaria", "Fernanda", "Ariel", "Fernando", "Francisco", "Sergio", "Candelaria", "Fernanda", "Ariel", "Fernando", "Francisco", "Sergio", "Candelaria", "Fernanda", "Ariel", "Fernando", "Francisco", "Sergio", "Candelaria", "Fernanda", "Ariel", "Fernando", "Francisco", "Sergio", "Candelaria", "Fernanda", "Ariel", "Fernando", "Francisco", "Sergio", "Candelaria", "Fernanda", "Ariel", "Fernando", "Francisco", "Sergio", "Candelaria", "Fernanda", "Ariel", "Fernando", "Francisco", "Sergio", "Candelaria", "Fernanda", "Ariel", "Fernando", "Francisco", "Sergio", "Candelaria", "Fernanda", "Ariel", "Fernando", "Francisco", "Sergio", "Candelaria", "Fernanda", "Ariel", "Fernando", "Francisco", "Sergio", "Candelaria", "Fernanda", "Ariel", "Fernando", "Francisco", "Sergio", "Candelaria", "Fernanda", "Ariel", "Fernando", "Francisco", "Sergio", "Candelaria", "Fernanda", "Ariel", "Fernando", "Francisco", "Sergio", "Candelaria", "Fernanda", "Ariel", "Fernando", "Francisco", "Sergio", "Candelaria", "Fernanda", "Ariel", "Fernando", "Francisco", "Sergio", "Candelaria", ""};
    int notas[] = {10, 6, 3, 2, 1, 4,10, 6, 3, 2, 1, 4,10, 6, 3, 2, 1, 4,10, 6, 3, 2, 1, 4,10, 6, 3, 2, 1, 4,10, 6, 3, 2, 1, 4,10, 6, 3, 2, 1, 4,10, 6, 3, 2, 1, 4,10, 6, 3, 2, 1, 4,10, 6, 3, 2, 1, 4,10, 6, 3, 2, 1, 4,10, 6, 3, 2, 1, 4,10, 6, 3, 2, 1, 4,10, 6, 3, 2, 1, 4,10, 6, 3, 2, 1, 4,10, 6, 3, 2, 1, 4,10, 6, 3, 2, 1, 4};
    int i;
    //char alumnos[][MAX_NOMBRE] = {"Fernanda", "Ariel", "Fernando", "Francisco", "Sergio", "Candelaria", "Fernanda", "Ariel", "Fernando", "Francisco", "Sergio", "Candelaria", ""};
    //int notas[] = {10, 10, 2, 10, 10, 10, 2, 2, 2, 2, 2, 2};
    
    char **aprob = alumnosAprobados(alumnos, notas);

    printf("\nAprobados:\n\n");
    for(i = 0; aprob[i][0] != '\0'; i++)
    {
        printf("%s\n", aprob[i]);
    }
    printf("\nTotal: %d\n", i);

    liberarMemoria(aprob);

    return 0;
}

char **
alumnosAprobados(tAlumnos alumnos, int notas[])
{
    char ** aprobados = NULL;
    int i = 0;
    int cantAprob = 0;

    while(alumnos[i][0] != '\0')
    {
        if(notas[i] >= 4)
        {
            if(cantAprob % BLOQUE == 0)
            {
                aprobados = realloc(aprobados, (cantAprob + BLOQUE) * sizeof(char *));
            }

            aprobados[cantAprob] = malloc((strlen(alumnos[i]) + 1) * sizeof(char));
            strcpy(aprobados[cantAprob], alumnos[i]);

            cantAprob++;
        }
        i++;
    }

    aprobados = realloc(aprobados, (cantAprob + 1) * sizeof(char *)); // Se le suma 1 porque es la cantidad de aprobados mas el string nulo
    aprobados[cantAprob] = malloc(sizeof(char));
    aprobados[cantAprob][0] = '\0'; //Agrega el string nulo la final. Lo hace a traves de heap
    //aprobados[cantAprob] = "";//Agrega el string nulo al final, lo hace apuntar a zona constante
    //Observacion 2: Primero hacer realloc, si no hay situaciones donde va a abortar (Cuando no quede lugar reservado para el "", cuando se llene el ultimo bloque)
    return aprobados;
}

void
liberarMemoria(char ** arreglo)
{
    int i;
    for(i = 0; arreglo[i][0] != '\0'; i++)
    {
        free(arreglo[i]);
    }
    free(arreglo[i]); //Libera el string nulo
    free(arreglo);
    return;
}

//Otra forma de copiar los nombres
            /*for(j = 0; alumnos[i][j] != '\0'; j++)
            {
                if(j % BLOQUE == 0)
                {
                    aprobados[cantAprob] = realloc(aprobados[cantAprob], (i + BLOQUE) * sizeof(char));
                }
                aprobados[cantAprob][j] = alumnos[i][j];
            }
            aprobados[cantAprob][j] = '\0';
            aprobados[cantAprob] = realloc(aprobados[cantAprob], j * sizeof(char));

            cantAprob++;*/