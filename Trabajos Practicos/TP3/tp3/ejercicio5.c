#include <stdio.h>

void 
main()
{
    int a, b, c;
    a = getchar();
    b = getchar();
    c = getchar();
    if(a >= 'B' && a <= 'Z' && a != 'E' && a != 'I' && a != 'O' && a != 'U')
    {
        printf("El carácter %c es una consontante mayúscula\n", a);
    }
    else
    {
        if(a >= 'b' && a <= 'z' && a != 'e' && a != 'i' && a != 'o' && a != 'u')
        {
            printf("El carácter %c es una consonante minúscula\n", a);
        }
        else
        {
            if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'A' || a == 'E' ||a == 'I' || a == 'O' ||a == 'U')
            {
                printf("El carácter %c es una vocal\n", a);
            }
            else
            {
                printf("El carácter %c no es una letra\n", a);
            }
        } 
    }
    if(b % 2 == 0)
        printf("El valor ASCII de %c es par\n", b);
    if(b >= '0' && b <= '9' && (b-'0')%2 == 0)
        printf("El carácter %c representa un dígito par\n", b);
    if((c >= 'A' && c <= 'Z') || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        printf("El carácter %c es una vocal o es mayúscula\n", c);
    if(((c >= 'B' && c <= 'Z') || (c >= 'b' && c <= 'a')) && c != 'e' && c != 'i' && c != 'o' && c != 'u')
        printf("El carácter %c no es una vocal pero es letra\n", c);
}
