/*
 * int pthread_key_create(pthread_key_t *key, void (*destr_function) (void *))
 *
 * ¸Ãº¯Êı´ÓTSD³ØÖĞ·ÖÅäÒ»Ïî£¬½«ÆäÖµ¸³¸økey¹©ÒÔºó·ÃÎÊÊ¹ÓÃ¡£Èç¹ûdestr_function²»Îª¿Õ£¬
 ÔÚÏß³ÌÍË³ö£¨pthread_exit()£©Ê±½«ÒÔkeyËù¹ØÁªµÄÊı¾İÎª²ÎÊıµ÷ÓÃdestr_function()£¬ÒÔÊÍ·Å·ÖÅäµÄ»º³åÇø¡£
 *
 * ×¢ÏúÒ»¸öTSD²ÉÓÃÈçÏÂAPI£º
 * int pthread_key_delete(pthread_key_t key)
 * Õâ¸öº¯Êı²¢²»¼ì²éµ±Ç°ÊÇ·ñÓĞÏß³ÌÕıÊ¹ÓÃ¸ÃTSD£¬Ò²²»»áµ÷ÓÃÇåÀíº¯Êı£¨destr_function£©£¬¶øÖ»ÊÇ½«TSDÊÍ·ÅÒÔ¹©ÏÂÒ»´Îµ÷ÓÃ pthread_key_create()Ê¹ÓÃ¡£
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
		//exit(0); //¿¿exit¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
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
