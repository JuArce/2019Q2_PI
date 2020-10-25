#include <stdio.h>
#include <math.h>

#define MASCARA_SUPERIOR 240
#define MASCARA_INFERIOR 15

double desviacionEstandar(const unsigned char vecto[], int cantidad);
double promedio(const unsigned char vector[], int cantidad);

int
main()
{
	unsigned char arreglo[] = {0x37, 0xF2, 0x03, 0x4A, 0xFF};
	int cantidad = 10;

	double desviacion = desviacionEstandar(arreglo, cantidad);

	printf("%g\n", desviacion);
}

/*
**Paso 1: calcular la media.
**Paso 2: calcular el cuadrado de la distancia a la media para cada dato.
**Paso 3: sumar los valores que resultaron del paso 2.
**Paso 4: dividir entre el número de datos.
**Paso 5: sacar la raíz cuadrada.
*/
double
desviacionEstandar(const unsigned char vector[], int cantidad)
{
	double prom = promedio(vector, cantidad);
	double sumaDistancias = 0;
	double desvEstandar;

	for(int i = 0; i < cantidad; i++)
	{
		if(i % 2 == 0)
		{
			sumaDistancias += pow((((vector[i / 2] & MASCARA_SUPERIOR) >> 4) - prom), 2);
		}
		else
		{
			sumaDistancias += pow(((vector[i / 2] & MASCARA_INFERIOR) - prom), 2);
		}
	}

	desvEstandar = sqrt(sumaDistancias / cantidad);
	return desvEstandar;
}

double 
promedio(const unsigned char vector[], int cantidad)
{
	double prom;
	int suma = 0;
	for(int i = 0; i < cantidad; i++)
	{
		if(i % 2 == 0)
		{
			suma += (vector[i / 2] & MASCARA_SUPERIOR) >> 4;
		}
		else
		{
			suma += (vector[i / 2] & MASCARA_INFERIOR);
		}
	}

	prom = (double)suma / cantidad;
	return prom;
}

