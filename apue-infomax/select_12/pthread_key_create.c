/*
 * int pthread_key_create(pthread_key_t *key, void (*destr_function) (void *))
 *
 * 该函数从TSD池中分配一项，将其值赋给key供以后访问使用。如果destr_function不为空，
 在线程退出（pthread_exit()）时将以key所关联的数据为参数调用destr_function()，以释放分配的缓冲区。
 *
 * 注销一个TSD采用如下API：
 * int pthread_key_delete(pthread_key_t key)
 * 这个函数并不检查当前是否有线程正使用该TSD，也不会调用清理函数（destr_function），而只是将TSD释放以供下一次调用 pthread_key_create()使用。
 */
#include <stdio.h>
#include <pthread.h>
pthread_key_t   key;
void echomsg(void* t)
{
        printf("destructor excuted in thread %d,param=%d\n",pthread_self(),*(int*)t);
}
void * child1(void *arg)
{
        int tid=pthread_self();
        printf("thread1 %d key:%d enter\n",tid,key);
        pthread_setspecific(key,(void *)tid);
        sleep(2);
        printf("thread1 %d returns %d\n",tid,pthread_getspecific(key));
        sleep(5);
}
void * child2(void *arg)
{
        int tid=pthread_self();
        printf("thread2 %d key:%d enter\n",tid,key);
        pthread_setspecific(key,(void *)tid);
        sleep(1);
        printf("thread2 %d returns %d\n",tid,pthread_getspecific(key));
        //sleep(5);
		pthread_exit(0);
		//exit(0); //靠exit靠靠靠靠靠靠靠靠靠靠靠靠靠靠靠�
}
int main(void)
{
        pthread_t tid1,tid2;
        pthread_key_create(&key,echomsg);
		printf("main key=%d\n",key);
        pthread_create(&tid1,NULL,child1,NULL);
        pthread_create(&tid2,NULL,child2,NULL);
        sleep(10);
		printf("main value:%d \n",pthread_getspecific(key));
        pthread_key_delete(key);
        printf("main thread exit\n");
        
		return 0;
}
