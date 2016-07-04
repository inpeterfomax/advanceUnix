#include<stdio.h>

#define Err(fmt,args...) printf("%d Err "fmt,__LINE__,##args)

int main()
{
	Err("%s","Hello world.\n");

	return 0;
}

