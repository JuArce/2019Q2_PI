#include <stdio.h>

int main()

{

char var, var1, var2, var3, var4;

var = getchar();

var1 = var>>6 & 0x3;

var2 = var>>4 & 0x3;

var3 = var>>2 & 0x3;

var4 = var & 0x3;

printf("%d\t%d\t%d\t%d\t%d\n",var, var1, var2, var3, var4);

return 0;

}