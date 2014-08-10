#include"head.h"
static void child_func(int signum)
{
	if(signum == SIGCHLD)
		printf("get ths SIGCHLD signal\n");
	else
		printf("catch the sinal :%d\n",signum);

	return;
}
int main()
{
	int ret;
	pid_t childpid;
	
	if( (ret = fork()) < 0)
		printf("fork failed!\n");
	if( ret == 0){
		printf("the child process!\n");
		exit(0);
	//		return;
	}
	if( ret > 0){
		printf("the father process!\n");
		if( signal(SIGCHLD,child_func) == SIG_ERR){
			printf("child has exit!\n");
		}else
			printf("install signal successed!\n");
		
		sleep(5);	//wait the child process terminate!
	}

	return 0;
}
