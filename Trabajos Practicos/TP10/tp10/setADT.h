#ifndef _setADT_h
#define _setADT_h

typedef struct setCDT * setADT;
typedef int elemType;

static int 
compare(elemType e1, elemType e2)
{
    return e1 - e2;
}

setADT newSet(); //Crea un nuevo conjunto
int addElem(setADT set, elemType elem); //Agrega el elemento y retorna 1 si lo pudo agregar. 0 si no.
int removeElem(setADT set, elemType elem); //Elimina el elemento elem del vector y retorna 1. Si no existe retorna 0
setADT unionSet(setADT s1, setADT s2); //Union
setADT intersecSet(setADT s1, setADT s2); //Interseccion
setADT substractSet(setADT s1, setADT s2); //Resta de s1 - s2
elemType getElem(setADT set, size_t index); //Retorna el index elemento del conjunto
int getDim(setADT set);
void freeSet(setADT set);

#endif