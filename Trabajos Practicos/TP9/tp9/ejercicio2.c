#include <stdio.h>

int suma(int num);

int
main()
{
    printf("%d\n", suma(1001));
    return 0;
}

int
suma(int num)
{
    if(num == 0)
    {
        return 0;
    }

    return (num % 10) + suma(num / 10);
}
