#include <stdio.h>

#define SWAP(t, x, y)   {t aux;\
                        aux = x; x = y; y = aux;\
                        }

int 
main()
{
    int a = 7, b = 9;
    printf("%d\t%d\n", a, b);
    SWAP(int, a, b);
    printf("%d\t%d\n", a, b);
    return 0;
}
            