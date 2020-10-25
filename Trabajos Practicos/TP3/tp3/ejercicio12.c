#include <stdio.h>

int
main()
{
    for(int i = 3; i <= 23; i += 5)
    {
        printf("%d\t", i);
    }
    
    putchar('\n');
    
    for(int i = 20; i >= -10; i -= 6)
    {
        printf("%d\t", i);
    }
    
    putchar('\n');
    
    for(int i = 19; i <= 51; i += 8)
    {
        printf("%d\t", i);
    }
    
    putchar('\n');
}