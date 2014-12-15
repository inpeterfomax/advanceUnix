#include<stdlib.h>
#include<pthread.h>

#include<stdio.h>


struct msg{
      struct msg *next;
	  int num;
};

struct msg  *head;

pthread_cond_t has_product = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void * consumer(void *p){
       struct msg *mp;
           // sleep(2);
	   for(; ; ){
			   printf("consumer begin to lock...\n");
            //  int n = pthread_mutex_trylock(&lock);
			 int n = pthread_mutex_lock(&lock);
		      printf("n=%d \n",n);
		      while(head == NULL){
					printf("head=NULL \n");
			   	   pthread_cond_wait(&has_product,&lock);
				   printf("consumer is wait....\n");
              }

		   mp = head;
		   head = mp->next;
		   pthread_mutex_unlock(&lock);
		   printf("consumer:%d \n",mp->num);
           free(mp);
           sleep(rand()%5);
	   }
}


void * producer(void *p){
      struct msg  *mp;
	  sleep(5);
      for(;;){
             mp = malloc(sizeof(struct msg));
			 mp->num = rand()%1000+1;
             printf("Producer:%d\n",mp->num);
             pthread_mutex_lock(&lock);
			 mp->next = head;
			 head = mp;
			 printf("producer begin to sleep(1) \n");
			 sleep(1);
			 pthread_mutex_unlock(&lock);
             sleep(5); 
			 pthread_cond_signal(&has_product);

			 sleep(rand()%5);
	  }
}



int main(void){
     pthread_t pid,cid;

	 pthread_create(&pid,NULL,producer,NULL);
	 pthread_create(&cid,NULL,consumer,NULL);

	 pthread_join(pid,NULL);
	 pthread_join(cid,NULL);


	 return 0;



}
