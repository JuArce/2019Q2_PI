#include <stdio.h>

int
main()
{
    printf("N\t10*N\t100*N\t1000*N\n");
    
    for(int n = 1; n <= 20; n++)
    {
        printf("%d\t%d\t%d\t%d\n", n, n*10, n*100, n*1000);
    }
    
    return 0;
}