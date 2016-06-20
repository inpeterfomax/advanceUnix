#include<stdio.h>

#define MYTAG "peter :"
#define MYDBG(format,args...) printf(MYTAG format,##args)


void main()
{
	char *str = "hello world.";
	MYDBG("%s \n",str);

}
