#include <stdio.h>

int sumaVec(int vec[], int dim);

int
main()
{
    int v[] = {1,2,3,4,5};
    printf("%d\n", sumaVec(v, 5));
    return 0;
}

int
sumaVec(int vec[], int dim)
{
    if(dim == 0)
    {
        return 0;
    }

    return vec[0] + sumaVec(vec + 1, dim - 1);
}