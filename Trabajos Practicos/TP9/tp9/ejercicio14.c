#include <stdio.h>

void piramide(int * latas, int * altura);

int
main()
{
    int latas = 1;
    int altura = 0;
    piramide(&latas, &altura);
    printf("%d\t%d\n", latas, altura);
}

void
piramide(int * latas, int * altura)
{
    if(*latas < ((*altura + 1) * (*altura + 1)))
    {
        return;
    }

    (*altura)++;
    *latas -= (*altura * *altura);
    piramide(latas, altura);
}