#include <stdio.h>

void
main()
{
    int x = 9, y = 11;
    if(x < 3)
    {
        printf("x < 3\n");
        if(y < 5)
        {
            printf("x < 3 y y < 5\n");
        }
    }   
    else
    {
        printf("x >= 3\n");
    }
}
