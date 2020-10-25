#include <stdio.h>

int balance(char * string);

int 
main()
{
    printf("%d\n", balance("56 + ( a - 7 - ( 12 +c) -t * 679)"));
    printf("%d\n", balance("56 + ( a - 7 -  12 +c) -t * 679)"));
    printf("%d\n", balance("+ ( a(10+c*567)-6/6) + 40"));
    printf("%d\n", balance("5 + 2 - 7)"));
    printf("%d\n", balance("((() 5 + (2 - 7"));

}

int
balance(char * string)
{
    if(*string == 0)
    {
        return 0;
    }

    if(*string == '(')
    {
        return 1 + balance(string + 1);
    }
    if(*string == ')')
    {
        return - 1 + balance(string + 1);
    }

    return balance(string + 1);
}