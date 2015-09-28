#include<stdio.h>
void main()
{
	char *ptr="11:13:1c:ed:43:c4";
	printf("length of %s is %d\n",ptr,strlen(ptr));

	int pid;
	pid = fork();
	if( pid > 0){
		printf("this is parent pid=%d \n",getpid());
	}else if(0 == pid){
		printf("this children pid = %d\n",getpid());
	}


	waitpid();

	return 0;
}
