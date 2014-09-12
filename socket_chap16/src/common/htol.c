#include"../include/head.h"
#include<arpa/inet.h>

int main()
{
	static int tmp=32;
	int conv = htol(tmp);
	printf("vonv:%d \n",conv);

	return 0;
}
