#include"../include/head.h"

int main(int argc,char* argv[])
{
	if(argc < 2)
		exit(-1);
	printf("value of %s is %s\n",argv[1],getenv(argv[1]));
	
	return 0;
}
