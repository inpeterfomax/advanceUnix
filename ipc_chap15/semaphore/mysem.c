#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <semaphore.h>
#include <time.h>
#include <assert.h>
#include <errno.h>
#include <signal.h>

struct  {
	sem_t mysem;
	int flag;
}mydata;

int main(void)
{
	int ret;
	mydata.flag = 1;
	if ( -1 == sem_init(&mydata.mysem,0,1)){
		perror("sem_init error\n");
		return(-1);
	}
	if( -1 == sem_wait(&mydata.mysem)){
		perror("sem_wait error\n");
		return(-1);
	}else{
		mydata.flag = 0;
		printf("%d has change flag value to %d\n",getpid(),mydata.flag);
	/*	if( -1 == sem_post(&mydata.mysem)){
			perror("sem_post error\n");
			return(-1);
		}*/
	}
	
	ret = fork();
	if( ret < 0)
		puts("fork error\n");
	else if( ret == 0){
		puts("in child\n");
		if( -1 == sem_wait(&mydata.mysem)){
			perror("sem_wait error\n");
			return(-1);
		} else {
			mydata.flag = -1;
			printf("%d has change flag value to %d\n",getpid(),mydata.flag);
			if( -1 == sem_post(&mydata.mysem)){
				perror("sem_post error\n");
				return(-1);
			}
		}
	}else{
		puts("in parent\n");
		sem_post(&mydata.mysem);
		
		sem_post(&mydata.mysem);
		wait(ret);
	}

	return 0;
}
