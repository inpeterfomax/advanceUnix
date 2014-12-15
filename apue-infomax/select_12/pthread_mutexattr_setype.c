#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
int main(void){
   pthread_mutex_t mutex;
   pthread_mutexattr_t attr;
   int err;

   err = pthread_mutexattr_init(&attr);
   if(err != 0)
		   return err;
   err = pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_NORMAL);//PTHREAD_MUTEX_ERRORCHECK,PTHREAD_MUTEX_RECURSIVE,PTHREAD_MUTEX_DERAULT
   if(err != 0)
		   return err;

    err = pthread_mutex_init(&mutex,&attr);
	err = pthread_mutex_lock( &mutex ); 
    fprintf(stderr, "before lock %d #1\n",err);
	err = pthread_mutex_lock( &mutex ); 
	fprintf(stderr, "before lock %d #2\n",err);
	err = pthread_mutex_lock( &mutex ); 
	fprintf(stderr, "before lock %d #3\n",err);
	err = pthread_mutex_unlock( &mutex ); 
	fprintf(stderr, "before unlock %d #1\n",err);
/*	err = pthread_mutex_unlock( &mutex ); 
	fprintf(stderr, "before unlock  %d #2\n",err);
	err = pthread_mutex_unlock( &mutex ); 
	fprintf(stderr, "before unlock err=%d#3\n",err);
	err = pthread_mutex_unlock( &mutex );  FAILS: assert(r == 0); */
//	fprintf(stderr, "before unlock err=%d #4\n",err);
}
