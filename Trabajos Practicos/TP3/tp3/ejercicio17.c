#include <stdio.h>

int 
main()
{
    for(int n = 10; n % 10 == 0 ;n *= 10)
    {
        printf("%d\n", n);
    }
}