#include <stdio.h>

int main(void)
{
	char a[8000000] = {0};
	char *ptr=a;
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	while(*ptr)
	{
	--ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	while(*ptr)
	{
	--ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	++ptr;
	--*ptr;
	}
	--ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	++*ptr;
	putchar(*ptr);
	while(*ptr)
	{
	++ptr;
	}
	--ptr;
	putchar(*ptr);
	while(*ptr)
	{
	--*ptr;
	}
	++ptr;
	++ptr;
	--*ptr;
	}
	return 0;
}
