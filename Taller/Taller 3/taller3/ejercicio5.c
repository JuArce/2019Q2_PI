#include <stdio.h>
/*
#define ELAPSED(h1, m1, h2, m2)	((h1)<(h2)) ? \
								((h2)-(h1))*60 + ((m2)-(m1)) \
								: ((h1)-(h2))*60 + \
								((m1)<(m2)) ? (m2)-(m1) : (m1)-(m2)
*/
#define ELAPSED(h1, m1, h2, m2) (((h1)*60+(m1)) > ((h2)*60+(m2))) ?\
								(((h1)*60+(m1))-((h2)*60+(m2))) :\
								(((h2)*60+(m2))-((h1)*60+(m1)))

#define TRUE 1
#define FALSE 0
#define NUMINVALIDO -2
#define NUMVALIDO 0

int minutosDesdeHasta(int h1, int m1, int h2, int m2);

void
main()
{
	int minutos;

	int h1, h2, m1, m2;

	h1 = 2; m1 = 10; h2 = 3; m2 = 15;

	minutos = ELAPSED(h1, m1, h2, m2); /*minutos = 65*/
	printf("%d\n", minutos);

	minutos = ELAPSED(3, 15, 4, 30);          /*minutos = 65*/
	printf("%d\n", minutos);

	minutos = ELAPSED(h1, m1, h1 + 1, m1);    /*minutos = 60*/
	printf("%d\n", minutos);

	minutos = minutosDesdeHasta(2, 15, 4, 0);
	printf("%d\n", minutos);
}

int
minutosDesdeHasta(int h1, int m1, int h2, int m2)
{
	int minutos = 0;

	if(validar(h1, m1, h2, m2) == NUMVALIDO)
	{
		if(h1 < h2)
		{
			minutos += (h2 - h1)*60 + (m2 - m1);
		}	
		else
		{
			if(m1 < m2)
				minutos += (h1 - h2)*60 + (m2 - m1);
			else
				minutos += (h1 - h2)*60 + (m1 - m2);
		}		
	}
	else
	{
		return NUMINVALIDO;
	}
	
}

int validar(int h1, int m1, int h2, int m2)
{
	int valido = NUMVALIDO;

	if(h1 > 23 || h2 > 23 || m1 > 59 || m2 > 59 || h1 < 0 || h2 < 0 || m1 < 0 || m2 < 0)
	{
		valido = NUMINVALIDO;
	}

	return valido;
} 