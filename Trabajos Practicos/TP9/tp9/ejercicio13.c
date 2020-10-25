#include <stdio.h>

int apareados(char * string);

int
main()
{
    printf("%d\n", apareados("()(()())"));
    printf("%d\n", apareados(")("));
    printf("%d\n", apareados(""));
    printf("%d\n", apareados("()("));
    printf("%d\n", apareados("(()())"));
    printf("%d\n", apareados("()())"));

}

int 
apareados(char * string)
{
    if(*string == 0)
    {
        return 0;
    }

    int aux = apareados(string + 1);

    if(aux < 0)
    {
        return aux;
    }

    if(*string == '(')
    {
        return aux - 1;
    }

    if(*string == ')')
    {
        return aux + 1;
    }
}