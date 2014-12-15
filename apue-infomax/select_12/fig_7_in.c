#include<pthread.h>
#include"apue.h"
pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;

void prepare(void){
    printf("prepare() lock....\n");
	pthread_mutex_lock(&lock1);
	pthread_mutex_lock(&lock2);
}

void parent(void){
  printf("parent() ....\n");
  pthread_mutex_unlock(&lock1);
  pthread_mutex_unlock(&lock2);
}

void child(void){
  printf("child() ....\n");
  pthread_mutex_unlock(&lock1);
  pthread_mutex_unlock(&lock2);
}

void* thr_fn(void* arg){
   printf("thread started ...\n");
//   pause();
   printf("pause done \n");
   return 0;
}


int main(void){
   int err;
   pid_t pid;
   pthread_t tid;

//   if((err=pthread_atfork(prepare,parent,child)) != 0)
//		   err_exit(err,"can't install fork handlers");
   prepare();
   err = pthread_create(&tid,NULL,thr_fn,NULL);
   if(err !=0)
		   err_exit(err,"pthread_create error");

    sleep(2);

	printf("parent about to fork....\n");
	if((pid=fork()) <0)
			err_quit("fork failed");
	else if(pid == 0){
	pthread_mutex_lock(&lock1);
	pthread_mutex_lock(&lock2);
			printf("child returned from fork \n");
	}else{
	pthread_mutex_lock(&lock1);
	pthread_mutex_lock(&lock2);
			printf("parent returned from fork \n");
    }
	exit(0);

}  

