#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int randInt(int min, int max);

int
main()
{   
    srand((int)time(NULL));
    for(int i = 0; i < 10; i++)
    {
        printf("%d\n", randInt(10, 100));
    }

} 

int
randInt(int min, int max)
{
    return (min + (max - min + 1) * (rand() / ((double)RAND_MAX + 1)));
}