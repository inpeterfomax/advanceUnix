#include<errno.h>
#include<stdlib.h>
#include <pthread.h>

struct foo{
  int a, b, c,d;
};

void printfoo(const char *s,const struct foo *fp){
    printf(s);
	printf(" structure at 0x%x\n",(unsigned)fp);
	printf(" foo.a = %d\n",fp->a);
	printf(" foo.b = %d\n",fp->b);
	printf(" foo.c = %d\n",fp->c);
    printf(" foo.d = %d\n",fp->d);
}

void* thr_fn1(void *arg){
   struct foo foo = {1,2,3,4};
   printfoo("thread 1:\n ",&foo);
   pthread_exit((void*)&foo);
}

void* thr_fn2(void *arg){
   printf("thread 2: ID is %d\n",pthread_self());
   pthread_exit((void*)0);
}

void print_attr(const pthread_attr_t *attr){
  int detachstate;
  int stacksize;
  size_t guardsize;

  pthread_attr_getdetachstate(attr,&detachstate);
  if(detachstate == PTHREAD_CREATE_DETACHED)
		  printf("分离状态:PTHREAD_CREATE_DETACHED\n",PTHREAD_CREATE_DETACHED);
  if(detachstate == PTHREAD_CREATE_JOINABLE)
		  printf("分离状态:PTHREAD_CREATE_JOINABLE\n",PTHREAD_CREATE_JOINABLE);
   
  pthread_attr_getstacksize(attr,&stacksize);
  printf("堆栈大小:%d\n",stacksize);
  pthread_attr_getguardsize(attr,&guardsize);
  printf("警戒堆栈尾大小:%d\n",guardsize);
  printf("当前的并发度:%d\n",pthread_getconcurrency()); 
}

void set_attr(pthread_attr_t *attr){
	pthread_attr_setdetachstate(attr,PTHREAD_CREATE_JOINABLE);	
    pthread_attr_setstacksize(attr,1024);
	pthread_attr_setguardsize(attr,512);
	pthread_setconcurrency(2);

}

int main(void){
    int err;
	pthread_t tid1,tid2;
	pthread_attr_t attr,attr1;
	struct foo *foo;
	
	err = pthread_attr_init(&attr);
	if(err !=0)
			return err;

	err = pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	if(err != 0)
			return err;
	err = pthread_create(&tid1,&attr,thr_fn1,NULL);

	if(err != 0)
			printf("can't create thread 1:%s\n",strerror(err));

	print_attr(&attr);
	pthread_attr_destroy(&attr);
    
	err = pthread_join(tid1,(void *)&foo);
	if(err != 0)
			printf("can't join thread 1:%s\n",strerror(err));
	 sleep(1);


	 printf("parent starting second thread\n");
     pthread_attr_init(&attr1);
	 set_attr(&attr1);
	 err = pthread_create(&tid2,&attr1,thr_fn2,NULL);
	if(err != 0)
			printf("can't create thread 2:%s\n",strerror(err));
	err = pthread_join(tid2,(void *)&foo);
	if(err != 0)
			printf("can't join thread 1:%s\n",strerror(err));
	print_attr(&attr1);
     pthread_attr_destroy(&attr1);

	 exit(0);
}
