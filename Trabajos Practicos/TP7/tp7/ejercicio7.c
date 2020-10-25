#include <stdio.h>
#include <math.h>
#include "getnum.h"
#include "random.h"
#include "getnum.h"

#define X 5 //Cantidad de digitos
#define MAX_LEVEL 10
#define TRUE 1
#define FALSE 0

void generaAleatorio(int incognita[], int digitos);
int elegirDigitos(void);
int elegirNivel(void);
void leerNumero(int numero[], int digitos);
int coincideNumero(int incognita[], int numero[], int digitos);
int cantidadBien(int incognita[], int numero[], int digitos);
int cantidadRegular(int incognita[], int numero[], int digitos);

int
main()
{
    randomize();
    int digitos = elegirDigitos();;
    int incognita[digitos];
    int numero[digitos];
    generaAleatorio(incognita, digitos);
    int nivel = elegirNivel();
    int intentos = MAX_LEVEL - nivel + 1;
    int iguales;

    do
    {
        leerNumero(numero, digitos); 
        iguales = coincideNumero(incognita, numero, digitos);
        intentos--;
    }while(!iguales && intentos);
    
    if(iguales)
    {
        printf("Usted ha adivinado el numero\n");
    }
    else
    {
        printf("Lo siento, el numero es "); 
        for(int i = 0; i < digitos; i++)
        {
            printf("%d", incognita[i]);
        }putchar('\n');
    }
    return 0;
}

void
generaAleatorio(int incognita[], int digitos)
{
    int numeros[] = {1,2,3,4,5,6,7,8,9};
    int n = 9;
    //int digitos = X;
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
elegirDigitos(void)
{
	int digitos;
	
	do
    {
    	digitos = getint("Ingrese la cantidad de digitos\n");
    }while(digitos < 0 || digitos > 9);

    return digitos;
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
leerNumero(int numero[], int digitos)
{
    int repetidos;
    //int digitos = X;
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
coincideNumero(int incognita[], int numero[], int digitos)
{
    int nBien = cantidadBien(incognita, numero, digitos);
    int nRegular = cantidadRegular(incognita, numero, digitos);
    int iguales = FALSE;
    //int digitos = X;

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
cantidadBien(int incognita[], int numero[], int digitos)
{
    //int dim = digitos;
    int nBien = 0; //Cantidad de numeros bien

    for(int i = 0; i < digitos; i++)
    {
        if(numero[i] == incognita[i])
        {
            nBien++;
        }
    }

    return nBien;
}

int
cantidadRegular(int incognita[], int numero[], int digitos)
{
    //int dim = X;
    int nRegular = 0;

    for(int i = 0; i < digitos; i++)
    {
        for(int j = 0; j < digitos; j++)
        {
            if(i != j && numero[i] == incognita[j])
            {
                nRegular++;
            }
        }
    }

    return nRegular;
}