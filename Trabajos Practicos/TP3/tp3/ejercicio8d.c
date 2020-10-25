#include <stdio.h>
#include <limits.h>

int main()
{
	//char short int long float double
	int a = 1;
	long b = 1;

	printf("Tipos con signo\n");
	printf("signed char: %d a %d\n", -(a << (sizeof(char)*8 -1)), (a << (sizeof(char)*8 -1)) -1);
	printf("signed short: %d a %d\n", -(a << (sizeof(short)*8 -1)), (a << (sizeof(short)*8 -1)) -1);
	printf("signed int: %d a %d\n", -(a << (sizeof(int)*8 -1)), (a << (sizeof(int)*8 -1)) -1);
	printf("signed long: %ld a %ld\n", -(b << (sizeof(long)*8 -1)), (b << (sizeof(long)*8 -1)) -1);	

	printf("\nTipos sin signo\n");
	printf("unsigned char: %d a %d\n", 0, (a << (sizeof(char)*8)) -1);
	printf("unsigned short: %d a %d\n", 0, (a << (sizeof(short)*8)) -1);
	printf("unsigned int: %d a %u\n", 0, (((unsigned int) 1) << (sizeof(int)*8)) -1);
	printf("unsigned long: %ld a %lu\n", 0L, (((unsigned long) 1) << (sizeof(long)*8)) -1);	
}					