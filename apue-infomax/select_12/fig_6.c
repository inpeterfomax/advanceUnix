#include"apue.h"
#include<pthread.h>

int  quitflag;
sigset_t mask;

pthread_mutex_t  lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  wait = PTHREAD_COND_INITIALIZER;

void* thr_fn(void* arg)
{
   int err,signo;
   sigset_t peing;
		   printf("thr_fn sleep(10) to ready pengingset\n");
		   sleep(10);
   for(;;){
       err = sigwait(&mask,&signo);
	   if(err != 0)
			   err_exit(err,"sigwait failed");
       switch(signo){
           case SIGINT:
				   printf("\ninterrupt\n");
				   break;
		   case SIGQUIT:
				   pthread_mutex_lock(&lock);
				   quitflag = 1;
				   pthread_mutex_unlock(&lock);
				   pthread_cond_signal(&wait);
                   return 0;
		   default:
				   printf("unexpected signal %d\n",signo);

	   }

   }

}
void sig_quit(int signo){
  printf("catcht SIGQUIT \n");

}
int main(void){
   int err;
   sigset_t oldmask;
   pthread_t tid;
   
   sigemptyset(&mask);
   sigaddset(&mask,SIGINT);
   sigaddset(&mask,SIGQUIT);

   if((err=pthread_sigmask(SIG_BLOCK,&mask,&oldmask)) != 0)
		   err_quit(err,"SIG_BLOCK error");

   err = pthread_create(&tid,NULL,thr_fn,0);
   if(err != 0)
		   err_quit(err,"can't create error");
  
   pthread_mutex_lock(&lock);
   while(quitflag == 0)
		   pthread_cond_wait(&wait,&lock);
   pthread_mutex_unlock(&lock);

   quitflag = 0;

   //测试由pthread_sigmask设定的屏蔽字，对进程是不是有影响？
   printf("sleep(5)....\n");
   signal(SIGQUIT,sig_quit);
   sleep(5);
   if(sigprocmask(SIG_SETMASK,&oldmask,NULL)<0)
		   err_sys("SIG_SETMASK err");

    exit(0);
}
