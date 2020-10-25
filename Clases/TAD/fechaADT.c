#include "fechaADT.h"

static enum formato fmt;

typedef struct fechaCDT
{
	int dia;
	int mes;
	int anio;
}fechaCDT;

fechaADT
nuevaFecha(int dia, int mes, int anio)
{
	if(...) //Valido
	{
		return NULL; //Si la fecha no es valida
	}

	fechaADT fecha = malloc(sizeof(fechaCDT));
	fecha->dia = dia;
	fecha->mes = mes;
	fecha->anio = anio;

	return fecha;
}

void
eliminaFecha(fechaADT f)
{
	free(f);
	return;
}

int
cambiaDia(fechaADT f, int nuevoDia)
{
	if(!esValido(nuevoDia, f->mes, f->anio))
	{
		return 0;
	}
	f->dia = nuevoDia;
	return 1;
}

void
fechaACadena(const fechaADT f, char s[])
{
	sprintf(s,"%02d/%02d/%d",
			f->dia, f->mes, f->anio);
	return;
}

void 
setearFormato(enum formato f)
{
	if(fmt >= dma && fmt <= amd)
	{
		fmt = f;
	}
	return;
}