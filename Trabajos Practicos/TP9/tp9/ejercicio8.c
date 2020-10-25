#include <stdio.h>

int ackermann(int m, int n);

int 
main()
{
    for(int n = 0; n < 10; n++)
    {
        for(int m = 0; m < 10; m++)
        {
            printf("%d\t%d\t%d\n", n, m, ackermann(n, m));
        }
    }
}

int
ackermann(int m, int n)
{
    if(m == 0)
    {
        return (n + 1);
    }

    if(n == 0 && m > 0)
    {
        return ackermann(m - 1, 1);
    }

    if(m > 0 && n > 0)
    {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}