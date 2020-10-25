#ifndef __fechaADT_h
	#define __fechaADT_h

enum formato {dma, mda, amd};

typedef struct fechaCDT * fechaADT;
fechaADT nuevaFecha(int dia, int mes, int anio);
void eliminaFecha(fechaADT f);
int cambiaDia(fechaADT f, int nuevoDia);
int dia(const fechaADT f);
void fechaACadena(const fechaADT fecha, char s[]);
void setearFormato(enum formato fmt);
