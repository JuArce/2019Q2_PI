#include <stdio.h>

void
main()
{
    int a;
    a = (getchar() != EOF);
    printf("%d\n", a);
}