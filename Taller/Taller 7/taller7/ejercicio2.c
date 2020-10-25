#include <stdio.h>

#define TRUE 1
#define FALSE 0

int comprimeCar(char * string, char car, int vec[], int maxDim);

int 
main()
{
	char s1[20] = "Aaa, bb aaaa cc aaa";

    char s2[20] = "Aaa bb aaaa cc aaa";

    int vec[20];

    int dim = comprimeCar(s1, 'a', vec, 20);  /* dim es 3, vec es {1, 3, 2} */

    printf("%s\n", s1);/* imprime Aa, bb a cc a*/ 

    for(int i = 0; i < dim; i++)
    {
    	printf("%d\t", vec[i]);
    }
    putchar('\n');

    dim = comprimeCar(s2, 'a', vec, 2);/* dim es 2, vec es {1, 3} */

    printf("%s\n", s2);/* imprime Aa bb a cc aaa*/

    for(int i = 0; i < dim; i++)
    {
    	printf("%d\t", vec[i]);
    }
    putchar('\n');
}

int
comprimeCar(char * string, char car, int vec[], int maxDim)
{
	char * aux = string;
	char * auxSalida = string;

	int i = 0;
	int flag = FALSE;

	/*Reiniciamos el vector para asegurar que no tenga basura*/
	for(int i = 0; i < maxDim; i++) 
	{
		vec[i] = 0;
	}

	/*Cuando el carácter actual coincide con car y con el siguiente, no copiamos
	**Aumentamos la cantidad de elementos que no se copiaron y ponemos flag en TRUE
	**El índice i se aumenta sólo cuando terminó de eliminar esa secuencia.
	**Se usa flag porque si no, se aumentaría i cada vez copia un carácter, lo cual
	**no es correcto. 
	*/
	while(*aux)
	{
		while(*aux == *(aux+1) && *aux == car)
		{
			aux++;	
			if(i < maxDim)
			{
				vec[i] += 1;
				flag = TRUE;	
			}
		}

		if(flag)
		{
			i++;
			flag = FALSE;
		}
		
		*auxSalida++ = *aux++;
	}

	*auxSalida = '\0';
	return i;
}