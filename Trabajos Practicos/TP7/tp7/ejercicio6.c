#include <stdio.h>
#include <math.h>
#include "getnum.h"
#include "random.h"
#include "getnum.h"

#define X 5 //Cantidad de digitos
#define MAX_LEVEL 10
#define TRUE 1
#define FALSE 0

void generaAleatorio(int incognita[]);
int elegirNivel(void);
void leerNumero(int numero[]);
int coincideNumero(int incognita[], int numero[]);
int cantidadBien(int incognita[], int numero[]);
int cantidadRegular(int incognita[], int numero[]);

int
main()
{
    randomize();
    int dim = X;
    int incognita[dim];
    int numero[dim];
    generaAleatorio(incognita);
    int nivel = elegirNivel();
    int intentos = MAX_LEVEL - nivel + 1;
    int iguales;

    do
    {
        leerNumero(numero); 
        iguales = coincideNumero(incognita, numero);
        intentos--;
    }while(!iguales && intentos);
    
    if(iguales)
    {
        printf("Usted ha adivinado el numero\n");
    }
    else
    {
        printf("Lo siento, el numero es "); 
        for(int i = 0; i < dim; i++)
        {
            printf("%d", incognita[i]);
        }putchar('\n');
    }
    return 0;
}

void
generaAleatorio(int incognita[])
{
    int numeros[] = {1,2,3,4,5,6,7,8,9};
    int n = 9;
    int digitos = X;
    int rnd;

    for(int i = 0; i < digitos; i++)
    {
        rnd = randInt(0, n-1);
        incognita[i] = numeros[rnd];
        numeros[rnd] = numeros[--n];
    }

    return;
}

int 
elegirNivel(void)
{
    int n;
    do
    {
        n = getint("Elija un nivel entre 1 y %d\n", MAX_LEVEL);
    } while (n < 1 || n > MAX_LEVEL);

    return n;    
}

void
leerNumero(int numero[])
{
    int repetidos;
    int digitos = X;
    int min = (int)pow(10, digitos - 1);
    int max = (int)pow(10, digitos) - 1;
    int n, aux;
    do
    {
        repetidos = FALSE;
        n = getint("Ingrese un numero de %d digitos sin repetidos\n", digitos);   
        aux = n;
        for(int i = digitos - 1; i >= 0 && !repetidos; i--)
        {
            numero[i] = aux % 10;
            aux /= 10;
            for(int j = i + 1; j < digitos; j++)
            {
                if(numero [j] == numero[i])
                {
                    repetidos = TRUE;
                }
            }
        }
    }while( n < min || n > max || repetidos);
}

int 
coincideNumero(int incognita[], int numero[])
{
    int nBien = cantidadBien(incognita, numero);
    int nRegular = cantidadRegular(incognita, numero);
    int iguales = FALSE;
    int digitos = X;

    if(nBien == digitos)
    {
        iguales = TRUE;
    }

    if(!iguales)
    {
        printf("%d bien. %d regular\n", nBien, nRegular);
    }

    return iguales;
}

int
cantidadBien(int incognita[], int numero[])
{
    int dim = X;
    int nBien = 0; //Cantidad de numeros bien

    for(int i = 0; i < dim; i++)
    {
        if(numero[i] == incognita[i])
        {
            nBien++;
        }
    }

    return nBien;
}

int
cantidadRegular(int incognita[], int numero[])
{
    int dim = X;
    int nRegular = 0;

    for(int i = 0; i < dim; i++)
    {
        for(int j = 0; j < dim; j++)
        {
            if(i != j && numero[i] == incognita[j])
            {
                nRegular++;
            }
        }
    }

    return nRegular;
}