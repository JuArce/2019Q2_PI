#include <stdio.h>

#define ENT_HORA 8
#define ENT_MINUTOS 30

int llegaTemprano(const int hora, const int minutos);

int
main()
{
    printf("%s\n", (llegaTemprano(8, 30)) ? "Llegó a horario" : "No llegó a horario");
    printf("%s\n", (llegaTemprano(7, 35)) ? "Llegó a horario" : "No llegó a horario");
    printf("%s\n", (llegaTemprano(9, 30)) ? "Llegó a horario" : "No llegó a horario");
    printf("%s\n", (llegaTemprano(8, 0)) ? "Llegó a horario" : "No llegó a horario");
    printf("%s\n", (llegaTemprano(9, 25)) ? "Llegó a horario" : "No llegó a horario");

}

int
llegaTemprano(const int hora, const int minutos)
{
    return ((hora < ENT_HORA) || (hora == ENT_HORA && minutos <= ENT_MINUTOS));
}
