#include <stdio.h>
#include <stdlib.h>

#define ELAPSED(h1, m1, h2, m2) abs((h1 - h2) * 60 + (m1 - m2))
                                
int
main()
{
    int h1, h2, m1, m2;
    h1 = 2; m1 = 10; h2 = 3; m2 = 15;
    
    printf("%d\n", ELAPSED(h1, m1, h2, m2));
    printf("%d\n", ELAPSED(3, 15, 2, 10));
    printf("%d\n", ELAPSED(h1, m1, h1 +1, m1));
}