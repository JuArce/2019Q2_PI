#include <stdio.h>

void
main()
{
    int i, lim;
    int s[lim];
    
    for(i = 0; i < lim - 1; i++)
    {
        if((c = getchar()) != '\n')
        {
            if(c != EOF)
            {
                s[i] = c;
            }
        }
    }
}