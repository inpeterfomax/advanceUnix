#include<pthread.h>
#include"apue.h"

void*thr_fn1(void*arg){
   printf("thread 1 returning \n");
   sleep(3);
   printf("thread2 end");
   return((void*)1);

}

void*thr_fn2(void*arg){
   printf("thread 2 exiting \n");

   pthread_exit((void*)2);

}


int main(void){
   int err;
   pthread_t tid1,tid2;
   void *tret;

   err=pthread_create(&tid1,NULL,thr_fn1,NULL);

   pthread_exit((void*)3);



}
