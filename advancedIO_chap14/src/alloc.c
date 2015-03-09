#include<stdio.h>
#include<string.h>

int main(int argc,char *argv[])
{
	char *srcptr = malloc(1024*1024*4);

	memset(ptr,0,1024*1024*4);

	char *tarptr = malloc(1024*1024*4);

	memcpy(tarptr,srcptr,1024*1024*4);

	return 0;
}
