/*
	pipe(fd); fd[0]:read interface,fd[1]:write interace;
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include<signal.h> 


static void sig_deal_fun(int signo){
	if(signo == SIGPIPE){
		printf("i have catch signal:SIGPIPE\n");
		return;
	}
	/*
	 *	do something else!
	 */
}

int main(void){
	int fd[2];
	pid_t pid;
	char line[1024];
	int n;

	if( signal(SIGPIPE,sig_deal_fun) == SIG_ERR ){
		printf("install signal failed\n");
		exit(-1);
	}
	if(pipe(fd) < 0){
		printf("pipe error\n");
		exit(-1);
	}
	/*try multi-process write senior*/
	dup();
	if((pid = fork())< 0){
		printf("fork failed\n");
		exit(-1);
	}else if(pid > 0){
		close(fd[0]);
		n = write(fd[1],"data from parent to child\n",sizeof("data from parent to child\n")); //write is horriable.
		if( n == -1)
			printf("SIGPIPE must have been dealed\n");
	}else{
		close(fd[1]);
		n = read(fd[0],line,256);
//		printf("get data from parent as following:%s\n",line);
		write(STDOUT_FILENO,line,n);
	}
	return 0;
}

