#include<stdio.h>
#include<pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  cond = PTHREAD_COND_INITIALIZER;

int threadcount = 5;
int threadids[5];

void * thread1(void* p){
    printf("1,thread1() threadid=0x%x \n",(unsigned int)pthread_self());    		
    pthread_mutex_lock(&mutex);
    printf("2,thread1() threadid=0x%x,call wait... \n",(unsigned int)pthread_self());
	pthread_cond_wait(&cond,&mutex);
    printf("3,thread1() threadid=0x%x end wait\n",(unsigned int)pthread_self());
	pthread_mutex_unlock(&mutex);
}


void* thread2(void*p){
  int i=0;
  for(i;i<1;i++){
      pthread_mutex_lock(&mutex);
	  printf("i=%d \n",i);
//      pthread_cond_signal(&cond);
	  pthread_cond_broadcast(&cond);
	  sleep(5);
	  pthread_mutex_unlock(&mutex);
//      sleep(5);
  }

}

int main(void){
 
	pthread_t threads[5];	
    pthread_create(&threads[0],NULL,thread1,NULL);
    pthread_create(&threads[1],NULL,thread1,NULL);
    pthread_create(&threads[2],NULL,thread1,NULL);
    pthread_create(&threads[3],NULL,thread1,NULL);
 
    sleep(10);	
    pthread_create(&threads[4],NULL,thread2,NULL);
   int i;
	for (i = 0; i < 5; i++) {
			    pthread_join(threads[i], NULL);
	 }
    printf("main exit\n");
}
