#include <stdio.h>
#include <ctype.h>

#include "random.h"

#define LETRAS 'Z' - 'A' + 1

void crearAlfabeto(char *alfabeto);
static void mezclarAlfabeto(char *alfabeto, int dim);
void codificar(char *alfabeto, char *mensaje, char *mjeCodificado);
void decodificar(char *alfabeto, char *mensaje, char *mjeDecodificado);
static int buscarLetra(char letra, char * alfabeto);

int
main()
{
    char alfa[LETRAS];
    crearAlfabeto(alfa);
    char string[] = "Call of Duty Modern Warfare";
    char string2[100];
    char string3[100];
    codificar(alfa, string, string2);
    printf("%s\n", string2);
    decodificar(alfa, string2, string3);
    printf("%s\n", string3);
}

void
crearAlfabeto(char *alfabeto)
{
    int dim = LETRAS;
    
    for(int i = 0; i < dim; i++)
    {
        alfabeto[i] = i + 'A';
    }

    mezclarAlfabeto(alfabeto, dim);

    return;
}

static void
mezclarAlfabeto(char *alfabeto, int dim)
{
    randomize();

    char aux; 
    int rand;

    for(int i = 0; i < dim; i++)
    {
        rand = randInt(0, dim - 1);
        aux = alfabeto[i];
        alfabeto[i] = alfabeto[rand];
        alfabeto[rand] = aux;
    }
    
    return;
}

void 
codificar(char *alfabeto, char *mensaje, char *mjeCodificado)
{
    int i = 0;
    int posicion;

    while(mensaje[i])
    {
        if(isalpha(mensaje[i]))
        {
            posicion = toupper(mensaje[i]) - 'A';
            mjeCodificado[i] = alfabeto[posicion];
        }
        else
        {
            mjeCodificado[i] = mensaje[i];    
        }
        i++;
    }

    mjeCodificado[i] = '\0';

    return;
}

void
decodificar(char *alfabeto, char *mensaje, char *mjeDecodificado)
{
    int i = 0;
    int letra;

    while(mensaje[i])
    {
        if(isalpha(mensaje[i]))
        {
            letra = buscarLetra(mensaje[i], alfabeto) + 'A';
            mjeDecodificado[i] = letra; 
        }
        else
        {
            mjeDecodificado[i] = mensaje[i];
        }
        i++;
    }

    mjeDecodificado[i] = '\0';

    return;
}

static int
buscarLetra(char letra, char * alfabeto)
{
    int dim = LETRAS;
    int i;
    for(i = 0; i < dim && letra != alfabeto[i]; i++);

    return i;
}