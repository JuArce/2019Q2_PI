#include <stdio.h>

int productoEscalar(int v1[], int v2[], int dim);

int
main()
{
    int v1[] = {1,2,3,4};
    int v2[] = {2,3,1,4};
    printf("%d\n", productoEscalar(v1, v2, 4));
}

int 
productoEscalar(int v1[], int v2[], int dim)
{
    if(dim == 0)
    {
        return 0;
    }

    return (v1[0] * v2[0]) + productoEscalar(v1 + 1, v2 + 1, dim - 1);
}