#include <sys/stat.h>   
#include <fcntl.h>   
#include <sys/mman.h>   
#include <unistd.h>   
  
  
#include <pthread.h>   
#include <stdio.h>   
#include <stdlib.h>   
  
  
  
  
int main(void){//2�����̣�һ���������ÿ�μ�1,��һ���������ÿ�μ�2,2������Э������ۼ�,ʹ�ù����ڴ淽ʽ�ڽ��̼�ͨ��   
  
int *x;   
int rt;   
int shm_id;   
char *addnum="myadd";   
char *ptr;   
  
pthread_mutex_t mutex;//�������   
pthread_mutexattr_t mutexattr;//�����������   
  
  
   pthread_mutexattr_init(&mutexattr);//��ʼ�������������   
   pthread_mutexattr_setpshared(&mutexattr,PTHREAD_PROCESS_SHARED);//���û������ΪPTHREAD_PROCESS_SHARED�����������ڶ�����̵��̷߳���,PTHREAD_PROCESS_PRIVATEΪͬһ���̵��̹߳���   
   rt=fork();//���Ƹ����̣��������ӽ���    
//deepfuture.iteye.com����δ������ԭ��   
   if (rt==0){//�ӽ������x+1   
       shm_id=shm_open(addnum,O_RDWR,0);   
       ptr=mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,shm_id,0);/*���ӹ����ڴ���*/  
       x=(int *)ptr;     
       int i; 
      for (i=0;i<10;i++){//��10�Ρ��൱�ڼ�10   
       pthread_mutex_lock(&mutex);         
       (*x)++;   
       printf("x++:%d\n",*x);   
       pthread_mutex_unlock(&mutex);    
       sleep(1);                    
      }   
   }      
   else{//���������x+2   
       shm_id=shm_open(addnum,O_RDWR|O_CREAT,0644);   
        ftruncate(shm_id,sizeof(int));   
        ptr=mmap(NULL,sizeof(int),PROT_READ|PROT_WRITE,MAP_SHARED,shm_id,0);/*���ӹ����ڴ���*/  
        x=(int *)ptr;    
           int i;  
      for ( i=0;i<10;i++){//��10�Σ��൱�ڼ�20   
       pthread_mutex_lock(&mutex);          
       (*x)+=2;   
       printf("x+=2:%d\n",*x);   
       pthread_mutex_unlock(&mutex);     
       sleep(1);    
      }         
         
   }    
   shm_unlink(addnum);//ɾ����������   
   munmap(ptr,sizeof(int));//ɾ�������ڴ�   
   return(0);   
}  
