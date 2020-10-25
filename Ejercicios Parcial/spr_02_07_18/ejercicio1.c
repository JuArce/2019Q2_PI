#include <stdio.h>


int orderVec(int vec[], int dim);


int
main()
{
    int v1[] = {1,2,3,4,5,6,7,8,9};
    int v2[] = {9,8,7,6,5,4,3,2,1};
    int v3[] = {1};
    int v4[] = {1,2,3,2,4,5,6,7,8};

    printf("%d\n", orderVec(v1, 9));
    printf("%d\n", orderVec(v2, 9));
    printf("%d\n", orderVec(v3, 1));
    printf("%d\n", orderVec(v4, 9));
}

int
orderVec(int vec[], int dim)
{
    if(dim <= 1)
    {
        return 0;
    }

    if(dim == 2)
    {
        if(vec[0] > vec[1])
        {
            return -1;
        }

        if(vec[0] < vec[1])
        {
            return 1;
        }

        return 0;
    }

    int ordenResto = orderVec(vec, dim - 1);

    if(vec[dim - 2] > vec[dim - 1] && ordenResto == -1)
    {
        return -1;
    }

    if(vec[dim - 2] < vec[dim - 1] && ordenResto == 1)
    {
        return 1;
    }

    return 0;
}