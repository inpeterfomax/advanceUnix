#include"head.h"

static void sig_usr(int usr){
	if(usr == SIGUSR1)
		puts("catch SIGUSR1\n");
	else if( usr == SIGUSR2)
		puts("catch SIGUSR2\n");
	else if(usr == SIGALRM)
		puts("alarm expires\n");
	else
		perror("error");

	return;
}

int main()
{
	int ret;
	printf("group id is: %d \n",getpid());
	if( signal(SIGUSR1,sig_usr) == SIG_ERR)
		puts("sigerr\n");

	if( signal(SIGUSR2,sig_usr) == SIG_ERR)
		puts("sigerr\n");
 
	if( signal(SIGALRM,sig_usr) == SIG_ERR)
		puts("sigerr\n");
	
	if( alarm(5) != 0 )	
		puts("alarm 5\n");

	printf("before while SIG_BLOCK=%d ..................\n",SIG_BLOCK);
	while(1)
		pause(); //suspend the process utill catches a signal.

	return 0;
}
