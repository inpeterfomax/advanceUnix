#include "head.h"

static void sig_func(int signum)
{
	printf("STDIN_FILENO %d,STDOUT_FILENO %d,STDERR_FILENO %d \n",STDIN_FILENO,STDOUT_FILENO,STDERR_FILENO);
	return;
}

int main()
{
	char line[128];
	int ret;

	if( signal(SIGALRM,sig_func) == SIG_ERR){
		perror("signal failed\n");
	}
	alarm(10);
	ret = read(STDIN_FILENO,line,128);	//fread(buff,elementsize,elementnum,FILE);
	if(ret < 0){
		printf("read failed\n");
	}
	alarm(0);

	write(STDOUT_FILENO,line,ret);

	exit(0);
}
