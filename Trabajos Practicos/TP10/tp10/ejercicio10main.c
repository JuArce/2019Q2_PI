#include <stdio.h>
#include <stdlib.h>
#include "bagADT.h"

int
main()
{
    bagADT bag = newBag();

    for(int i = 0; i < 10; i++)
    {
        add(bag, 26);
    }
    for(int i = 0; i < 4; i++)
    {
        add(bag, 12);
        add(bag, 97);
    }
    for(int i = 0; i < 6; i++)
    {
        add(bag, 22);
    }

    printf("26: %d\n", count(bag, 26));
    printf("12: %d\n", count(bag, 12));
    printf("11: %d\n", count(bag, 11));

    printf("Size: %d\n", size(bag));

    printf("Most Popular: %d\n", mostPopular(bag));
}