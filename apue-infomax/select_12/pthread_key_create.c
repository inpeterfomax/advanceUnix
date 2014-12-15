/*
 * int pthread_key_create(pthread_key_t *key, void (*destr_function) (void *))
 *
 * �ú�����TSD���з���һ�����ֵ����key���Ժ����ʹ�á����destr_function��Ϊ�գ�
 ���߳��˳���pthread_exit()��ʱ����key������������Ϊ��������destr_function()�����ͷŷ���Ļ�������
 *
 * ע��һ��TSD��������API��
 * int pthread_key_delete(pthread_key_t key)
 * �������������鵱ǰ�Ƿ����߳���ʹ�ø�TSD��Ҳ���������������destr_function������ֻ�ǽ�TSD�ͷ��Թ���һ�ε��� pthread_key_create()ʹ�á�
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
		//exit(0); //��exit�������������������������������
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
