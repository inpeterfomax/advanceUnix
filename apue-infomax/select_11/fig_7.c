#include<stdlib.h>
#include<pthread.h>


#define NHASH 29
#define HASH(fp) ((unsigned long)fp%NHASH)

pthread_mutex_t haslock = PTHREAD_MUTEX_INITIALIZER;

struct foo{
   int f_count;
   pthread_mutex_t f_logk;
   struct foo *next;
   int f_id;
};



struct foo* foo_alloc(void){
     struct foo * fp;
	 int  idx;

	 if((fp=malloc(sizeof(struct foo))) != NULL){
              fp


	 }



}
