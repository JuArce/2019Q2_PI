#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define BLOQUE 5
#define MAX 40

void separaCursos(char nombres[MAX][MAX], char curso[], char cursoG[MAX][MAX], char cursoH[MAX][MAX]);

int
main()
{
    char curso[] = {"GHHG"};
    char nombres[MAX][MAX] = {"Juan P", "Juana A", "Juanss S", "Juan K", ""};
    char cursoG[MAX][MAX];
    char cursoH[MAX][MAX];
    int i;
    separaCursos(nombres, curso, cursoG, cursoH);
    i = 0;
    while(cursoG[i][0] != '\0')
    {   
        putchar('G');
        printf("%s\n", cursoG[i++]);
    }
    i = 0;
    while(cursoH[i][0] != '\0')
    {   
        putchar('H');
        printf("%s\n", cursoH[i++]);
    }

}

void 
separaCursos(char nombres[MAX][MAX], char curso[], char cursoG[MAX][MAX], char cursoH[MAX][MAX])
{
    int i = 0;
    int indG = 0, indH = 0;
    while(nombres[i][0] != 0)
    {
        if(curso[i] == 'G')
        {
            strcpy(cursoG[indG++], nombres[i]);
        }
        else
        {
            strcpy(cursoH[indH++], nombres[i]);
        }
        i++;
    }
    cursoG[indG][0] = '\0';
    cursoH[indH][0] = '\0';
    return;
}