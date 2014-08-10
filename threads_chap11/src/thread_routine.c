#include<pthread.h>
#include<unistd.h>
#include<stdio.h>

typedef struct __hello{
	int a;
	int c;
	char *b;
	void *d;
}mytype;

void* thread_fun_srv_1(void *a)
{	
	mytype *tmp = (mytype *)a;
	while(1)
		printf("this is function %s tmp->a:%d\n",__func__,tmp->a);
}

void* thread_fun_srv_2(void* a)
{
	mytype *tmp = (mytype *)a;
	while(1)
		printf("this is function %s tmp->a:%d\n",__func__,tmp->a);
}

int main()
{
	int ret;
	pthread_t pthread1,pthread2;
	mytype a={1,2,NULL,NULL};
	ret = pthread_create(&pthread1,NULL,thread_fun_srv_1,&a);
	if(ret != 0 ){
		printf("create thread filed +++++++++++\n");
	}
	ret = pthread_create(&pthread1,NULL,thread_fun_srv_2,&a);
	if(ret != 0 ){
		printf("create thread filed ----------\n");
	}

	pause();//means the main thead to suspend.
	//	while(1);
}
