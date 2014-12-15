#include<stdio.h>
#include<pthread.h>
pthread_mutex_t count_lock=PTHREAD_MUTEX_INITIALIZER; 
pthread_cond_t count_hit_threshold=PTHREAD_COND_INITIALIZER; 

void* watch_thr1(void * p){
  pthread_mutex_lock(&count_lock);

  printf("watch_thr1(): begin to call pthread_cond_wait() \n");
  int cond = pthread_cond_wait(&count_hit_threshold,&count_lock);
  printf("begin to sleep(5) cond=%d\n",cond);
  sleep(5);
  pthread_mutex_unlock(&count_lock);
  printf("watch_thr1() unlock() \n");
}


void * watch_thr2(void* p){
   pthread_mutex_lock(&count_lock);
  printf("watch_thr2(): begin to call pthread_cond_broadcast() \n");
  pthread_cond_broadcast(&count_hit_threshold);
  printf("watch_thr2(): end to call pthread_cond_broadcast() \n");
   int i,j;
   int sum;
    for(i=0;i<1000;i++)
			for(j=0;j<100000;j++){
               sum += i*j;
			   if(sum/1000 ==0)
			   printf("%d \n", sum);
         }
   pthread_mutex_unlock(&count_lock);


}



int main(void){
    int i;
    pthread_t threads[2];
	pthread_create(&threads[0], NULL, watch_thr1, NULL);
	sleep(1);
	pthread_create(&threads[1], NULL, watch_thr2,   NULL);
     for (i = 0; i < 2; i++) {
			     pthread_join(threads[i], NULL);
		}
}
