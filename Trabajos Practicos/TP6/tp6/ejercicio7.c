#include <stdio.h>

#define MAX 100

void unionOrdenada(const int vec1[], const int vec2[], int vecRespuesta[]);

int
main()
{
    int vec1[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,18,19,20,-1};
    int vec2[] = {2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,-1};
    int vec3[MAX] = {0}; 

    unionOrdenada(vec1, vec2, vec3);

    for(int i = 0; vec3[i] != -1; i++)
    {
        printf("%d\t", vec3[i]);
    }
    putchar('\n');
}

void
unionOrdenada(const int vec1[], const int vec2[], int vecRespuesta[])
{
    int i = 0, j = 0, k = 0; //i subindice vec1; j subindice vec2; k subindice vecRespuesta

    while(vec1[i] != -1 && vec2[j] != -1 && k < MAX - 1)
    {
        if(vec1[i] == vec2[j])
        {
            vecRespuesta[k++] = vec1[i];
            i++; j++;
        }
        else if(vec1[i] < vec2[j])
        {
            vecRespuesta[k++] = vec1[i++];
        }
        else if(vec1[i] > vec2[j])
        {
            vecRespuesta[k++] = vec2[j++];
        }
    }

    while(vec1[i] != -1 && k < MAX - 1)
    {
        vecRespuesta[k++] = vec1[i++];
    }

    while(vec2[j] != -1 && k < MAX - 1)
    {
        vecRespuesta[k++] = vec2[j++];
    }
    
    vecRespuesta[k] = -1;
    return;
}