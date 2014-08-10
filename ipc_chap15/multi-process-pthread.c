/*
 *to prove that wihile in 
 * */

#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<signal.h>
#include<pthread.h>


void * pth_fun(void *argc){
	while(1){
		puts("in pth_fun \n");
	}
	
	return ((void *)0);
}

int main(){

	char tmp;
	int ret,pthret;
	pid_t pid;
	pthread_t pthid;

	if( (ret = fork()) < 0)
		puts("fork failed \n");
	else if( ret == 0){
		if( (pthret = pthread_create(&pthid,NULL,pth_fun,NULL))!= 0 )
			puts("pthread_creade failed\n");
		pthread_join(pthid,NULL);

		return 0;	

	}else{

		kill(pid,9);	
		puts("parent process");
		while(1){
			tmp = getchar();
			switch(tmp){
				case 'k':
					putchar(tmp);
					puts("going to kill child\n");
					break;
				case 'b':
					printf("is a b\n");
					break;
				default:
					break;
			}
			break;
		}
	}

	return 0;
}
