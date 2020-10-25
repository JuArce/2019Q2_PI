#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complexADT.h"

typedef struct complexCDT
{
    double re; //Parte real
    double im; //Parte imaginaria
}complexCDT;

/*Crea un nuevo numero complejo*/
complexADT 
newComplex(double re, double im)
{
    complexADT z = malloc(sizeof(complexCDT));
    z->re = re;
    z->im = im;
    return z;
}

/*Cambia la parte real del complejo pasado como parametro
*por el segundo parametro (double)
*/
void 
changeRe(complexADT z, double newRe)
{
    z->re = newRe;
    return;
}

void 
changeIm(complexADT z, double newIm)
{
    z->im = newIm;
}

double 
getRe(complexADT z)
{
    return z->re;
}

double 
getIm(complexADT z)
{
    return z->im;
}

double 
getMod(complexADT z)
{
    double mod = sqrt(pow(z->re, 2) + pow(z->im, 2));
    return mod;
}

double 
getArg(complexADT z)
{
    double arg = atan(z->im / z->re);
    return arg;
}

complexADT 
sum(complexADT z1, complexADT z2)
{
    double re = z1->re + z2->re;
    double im = z1->im + z2->im;
    complexADT z3 = newComplex(re, im);
    return z3;
}

complexADT 
prod(complexADT z1, complexADT z2)
{
    double re = (z1->re * z2->re) + (z1->im * z2->im);
    double im = (z1->re * z2->im) + (z1->im * z2->re);
    complexADT z3 = newComplex(re, im);
    return z3;
}

void 
freeComplex(complexADT z)
{   
    free(z);
    return;
}