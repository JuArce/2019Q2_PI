#include <stdio.h>
#include <string.h>

int esCapicua(char * string);
static int esCapicuaRec(char * string, int length);

int
main()
{
    printf("%d\n", esCapicua("anitalavalatina"));
    printf("%d\n", esCapicua("anita"));
    return 0;
}

int
esCapicua(char * string)
{
    int length = strlen(string);
    return esCapicuaRec(string, length);
}

static int
esCapicuaRec(char * string, int length)
{
    if(*string == '\0')
    {
        return 1;
    }

    return (string[0] == string[length - 1]) && esCapicuaRec(string + 1, length - 2);
}