#ifndef _complexADT_h
#define _complexADT_h

typedef struct complexCDT * complexADT;

/*Crea un nuevo numero complejo*/
complexADT newComplex(double re, double im);

/*Cambia la parte real del complejo pasado como parametro
*por el segundo parametro (double)
*/
void changeRe(complexADT z, double newRe);

void changeIm(complexADT z, double newIm);

double getRe(complexADT z);

double getIm(complexADT z);

double getMod(complexADT z);

double getArg(complexADT z);

complexADT sum(complexADT z1, complexADT z2);

complexADT prod(complexADT z1, complexADT z2);

void freeComplex(complexADT z);

#endif