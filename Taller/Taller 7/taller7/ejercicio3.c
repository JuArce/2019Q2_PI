#include <stdio.h>

#define DIRECCIONES 8
#define TRUE 1
#define FALSE 0
#define X 0
#define Y 1
#define COLUMNAS 6


int calculaDireccion(int matriz[][COLUMNAS], int filas, int columnas, int posX, int posY);

int
main()
{
	int tablero[7][6] = {{0,  0,  0,  0,   1,  0},
					     {'X','X',0,  0,   0,  0},
					     {0,  0,  0,  0,  'X', 0},
					     {1,  1,  1,  0,   0,  0},
					     {1,  2,  1,  1,   0,  0},
					     {1,  1,  1,  'X', 0,  0},
				         {1,  0,  0,  'X','X','X'}};

	int a = calculaDireccion(tablero, 7, 6, 1, 4);
	printf("%d\n", a);
	return 0;
}

int
calculaDireccion(int matriz[][COLUMNAS], int filas ,int columnas, int posX, int posY)
{
	int max = 0;
	int maxDir = -1;
	int aux;
	int auxX, auxY;
	int bloqueo;
	int i, j;

	//Vector de versores con las direcciones correspondientes
	int dirs[2][DIRECCIONES] = {{ 1,  1,  0, -1, -1, -1, 0, 1},
					 			{ 0, -1, -1, -1,  0,  1, 1, 1}};

	for(int direccion = 0; direccion < DIRECCIONES; direccion++)//Setea la direccion. Empieza en Este, y va en sentido antihorario
	{
		aux = 0; //Calcula la maxima cantidad de movimientos
		i = 1; j = 1; //Multiplicadores
		bloqueo = FALSE; //Indica si hay un bloqueo en la direccion tomada 	
		auxX = posX; //Se va a mover en el eje x a partir de posX
		auxY = posY; //Se va a mover en el eje y a partir de posY

		while(auxY < filas-1 && auxY > 0 && auxX < columnas-1 && auxX > 0 && !bloqueo)
		{
			auxX = posX + i * dirs[X][direccion]; //Avanza a la siguiente posicion en el sentido del versor direccion en el eje x
			auxY = posY + j * dirs[Y][direccion]; //Avanza a la siguiente posicion en el sentido del versor direccion en el eje y

			if(matriz[auxY][auxX] != 1 && matriz[auxY][auxX] != 'X') //Si no existe un bloque, puede seguir avanzando
			{
				aux++;
				i++; j++;
			}
			else
			{
				bloqueo = TRUE;
			}
		}

		if(aux > max)
		{
			max = aux;
			maxDir = 45 * direccion;
		}
	}

	return maxDir;
}
