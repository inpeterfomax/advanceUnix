#include<stdio.h>

#define XXX 0

int main(int argc,char*argv[])
{
#if 0
	if( argc  < 2)
	{
		perror("need more paremeters\n");
		return - 1;
	}else if( argv[1] > 0){
		;
		#define XXX 0
	}
	else if( argv[1] < 0){
		;
		#define XXX -1
	}
	else{
		;
		#define XXX 0 
	}
#endif 		
#if XXX
	printf("if XXX ...\n");
#else
	printf("else xxx 111...\n");
#endif

#ifdef XXX
	printf("ifdef XXX ...\n");
#else
	printf("else XXX 222...\n");
#endif

#if defined(XXX)
	printf("if defined( XXX ) ...\n");
#else
	printf("else XXX 333 ...\n");

#endif
 	return 0;
}




