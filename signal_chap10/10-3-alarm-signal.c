#include "head.h"
static void sing_fun(int sig_num)
{
	if( sig_num == SIGALRM)
		printf("%s,signum=%d\n","catch the alarm signal",sig_num);
	//exit(-1);
	return;
}
int main()
{
	if( signal(SIGALRM,sing_fun) == SIG_ERR){
		printf("signal failed\n");
	}
	alarm(3);	
	pause();
	printf("keep going+++++++++++\n");
	return (alarm(0));
}
