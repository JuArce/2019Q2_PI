#include <stdio.h>

void
main()
{
    int x = 9, y = 11;
    if(x == 1)
    {
        if(y > 1)
        {
            printf("x == 1 y y > 1\n");
        }
    }
    else
    {
        if(x > 1)
        {
            printf("x > 1\n");
        }
        else
        {
            printf("x < 1\n");
        }
    }
}
