#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<signal.h>

//#include<err.h>
//#include<string.h>

int main()
{
	pid_t childpid;
	pid_t grandpid;
	int i;
	if( ( childpid = fork()) < 0){
		printf("fork failed %s\n",strerror(errno));
	}else if( childpid == 0){
		if( ( grandpid = fork()) < 0){
			printf("fork failed again %s\n",strerror(errno));	
		}else if( grandpid == 0){
			char buf1[32] = {'\0'};
			sprintf(buf1,"%s %s","this is","hello wrold\n");
			printf("buf1:%s\n",buf1);
			for(i=0;i<32;i++){
				sleep(1);
				printf("my pid is :%d myparent is:%d\n",getpid(),getppid());
			}
		}
		sleep(6); //try to wait a minute
		exit(0); //childpid return;
	}
	waitpid(childpid,NULL,0);
	
	sleep(6);

//	kill(grandpid,SIGTERM);
	//printf("grandpid :%d \n",grandpid);
	return 0;
}


