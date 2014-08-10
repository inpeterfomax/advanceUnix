#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>

#if 0
int main(int argc,char *argv[])
{
	int i=0,wait_ret,j;
	printf("there are %d parameters from command-line\n",argc);
	printf("the parame are:");
	for( i ;i < argc;i ++){
		printf("%s ",argv[i]);
	}
	printf("\n");

	pid_t pid,pid2;

	pid = fork();
	if(pid < 0){
		printf("fork failed!\n");
	}else if( pid == 0){
		printf("im the child process %d,my parent is %d\n",getpid(),getppid());//fork retirn from child;
	}else
		printf("im the parent process %d,my parent is %d\n",getpid(),getppid());//fork return from parent;
/*race condition happends,the lively breeding ground for race conditions*/
	j++;
	pid_t pidchild = waitpid(-1,&wait_ret,0);
	if( pidchild < 0 ){
		
		printf("child process run first,wait_pid for the child process:%d\n",pidchild);
	}else
		printf("parent process run first,wait_pid for the child process:%d\n",pidchild);

	printf("the last process %d\n",getpid());

	return 0;
}
#endif
static void charatatime(char *str)
{
	char *ptr;
	int c;
	
	setbuf(stdout,NULL);
	for( ptr= str;(c = *ptr++) != 0;)
		putc(c,stdout);
}
int main()
{
	pid_t pid;
	
	if((pid = fork()) < 0){
		puts("fork error\n");
	}else if( pid == 0){
		charatatime("output from child \n");
	}else{
		charatatime("output from parent \n");
	}
	exit(0);
}
