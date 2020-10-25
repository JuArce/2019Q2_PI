#include <stdio.h>

void
main()
{
	double fahr, celsius;
	printf("Celsius\t\tFahrenheit\n");
	for(celsius = 0; celsius <= 100; celsius += 5)
	{
		fahr = celsius * (9.0/5) + 32;
		printf("%.2f\t\t%.2f\n", celsius, fahr);
	}
}