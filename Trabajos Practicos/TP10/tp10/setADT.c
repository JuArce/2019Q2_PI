#include <stdio.h>
#include <stdlib.h>
#include "setADT.h"

#define BLOQUE 5
#define TRUE 1
#define FALSE 0

typedef struct setCDT
{
    elemType * elems;
    size_t dim; //Cantidad de elementos del vector
    size_t size; //Espacio reservado en memoria
}setCDT;

static int aparece(elemType elems[], size_t dim, elemType elem);

setADT 
newSet()
{
    return calloc(1, sizeof(setCDT));
}

static int 
aparece(elemType elems[], size_t dim, elemType elem) //Si el elemento aparece, devuelve la posicion + 1
{
    for(int i = 0; i < dim; i++)
    {
        if(compare(elems[i], elem) == 0)
        {
            return i + 1;
        }
    }

    return 0;
}

int 
addElem(setADT set, elemType elem)
{
    if(!aparece(set->elems, set->dim, elem))
    {
        if(set->dim == set->size)
        {
            set->elems = realloc(set->elems, (set->size + BLOQUE) * sizeof(elemType));
            set->size += BLOQUE;
        }
        set->elems[set->dim] = elem;
        (set->dim)++;
        return 1;
    }

    return 0;
}

int 
removeElem(setADT set, elemType elem)
{
    int index; //Indica el i-esimo elemento
    if((index = aparece(set->elems, set->dim, elem)))
    {
        set->elems[index - 1] = set->elems[set->dim - 1]; //Pisa el elemento a borrar con el ultimo elemento del vector
        (set->dim)--;
        return 1;
    }
    return 0;
}

setADT 
unionSet(setADT s1, setADT s2)
{
    setADT s3 = newSet();
    s3->elems = malloc(s1->dim * sizeof(elemType));
    s3->dim = s1->dim;
    s3->size = s1->dim;

    //Copio todo el primer conjunto
    for(int i = 0; i < s1->dim; i++)
    {
        s3->elems[i] = s1->elems[i];
    }

    //Copio los elementos del segundo conjunto que no esten ya copiados (Que no existan en el primer vector)
    for(int i = 0; i < s2->dim; i++)
    {
        if(!aparece(s3->elems, s3->size, s2->elems[i]))
        {
            if(s3->dim == s3->size)
            {
                s3->elems = realloc(s3->elems, (s3->size + BLOQUE) * sizeof(elemType));
                s3->size += BLOQUE;
            }
            s3->elems[s3->dim] = s2->elems[i];
            (s3->dim)++;  
        }
    }

    return s3;
}

setADT 
intersecSet(setADT s1, setADT s2)
{
    setADT s3 = newSet();
    int flag = TRUE;

    for(int i = 0; i < s1->dim; i++)
    {
        for(int j = 0; j < s2->dim && flag; j++)
        {
            if(compare(s1->elems[i], s2->elems[j]) == 0)
            {
                if(s3->dim == s3->size)
                {
                    s3->elems = realloc(s3->elems, (s3->size + BLOQUE) * sizeof(elemType));
                }
                s3->elems[s3->dim] = s2->elems[j];
                (s3->dim)++;
                flag = FALSE;
            }
        }
        flag = TRUE;
    }

    return s3;
}

setADT 
substractSet(setADT s1, setADT s2)
{   

}

elemType 
getElem(setADT set, size_t index) //Retorna el index elemento del conjunto
{
    if(index <= set->dim)
    {
        return set->elems[index - 1];
    }
    printf("Acceso invalido\n");
}

int 
getDim(setADT set)
{
    return set->dim;
}

void 
freeSet(setADT set)
{
    free(set->elems);
    free(set);
    return;
}