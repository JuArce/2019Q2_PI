#include <stdio.h>

void main()
{
    int c;
    c = getchar();
    if(c >= 'A' && c <= 'Z')
    {
        printf("El carácter '%c' es una letra mayúscula\n", c);
    }
    else if(c >= 'a' && c <= 'z')
    {
        printf("El carácter '%c' es una letra minúscula\n", c);
    }
    else
    {
        printf("El carácter '%c' no es una letra\n", c);;
    }
    return;
}
