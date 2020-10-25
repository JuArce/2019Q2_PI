#include <stdio.h>
#include "stackADT.h"

#define OPEN "([{"
#define CLOSE ")]}"

int match(const char * s);

int
main()
{

}

int
match(const char * s)
{	
	stackADT stack = newStack();

	for(int i = 0; s[i] != 0; i++)
	{
		if(open(s[i]))
		{
			push(stack, s[i]);
		}
		else if(isEmpty(stack) || change(s[i]) != pop(stack))
		{
			freeStack(stack);
			return 0;
		}
	}

	int aux = isEmpty(stack);
	freeStack(stack);
	return aux;
}

int 
open(char c)
{
	return strchr(OPEN, c) != NULL;
}

char
change(char c)
{
	char * pos = strchr(OPEN, c);
	if(pos == NULL)
	{
		return '\0';
	}
	return OPEN[pos - CLOSE];
}