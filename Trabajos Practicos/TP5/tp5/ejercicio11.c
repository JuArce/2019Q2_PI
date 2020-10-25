#include <stdio.h>
#include <ctype.h>

int
main()
{
    int a, b, c;
    a = getchar();
    b = getchar();
    c = getchar();

    if(isupper(c) && !(a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U'))
    {
        printf("El carácter %c es una consontante mayúscula\n", a);
    }
    else
    {
        if(islower(c) && !(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'))
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
    if(isdigit(b) && (b -'0')%2 == 0)
        printf("El carácter %c representa un dígito par\n", b);
    if((isupper(c)) || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        printf("El carácter %c es una vocal o es mayúscula\n", c);
    if(isalpha(c) && !(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') && !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'))
        printf("El carácter %c no es una vocal pero es letra\n", c);
}



