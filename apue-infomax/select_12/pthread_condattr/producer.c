#include"common.h"

int main(void){
    int fd;
	int i;
	struct share_struct *shareinfo;

	fd = shm_open(SHARE_PATH,SHARE_FLAG,SHARE_MODE);
	if(fd<0){
      perror("shm_open");
	   return -1;
	}

	if(ftruncate(fd,SHARE_LEN)<0){
       perror("ftruncate");
       return -1;
	}

   shareinfo = mmap(NULL,sizeof(struct share_struct),PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if(shareinfo <0){
       perror("mmap");
	   return -1;
	}

	close(fd);


	pthread_mutexattr_t mutexattr;
	pthread_condattr_t condattr;

	if(pthread_mutexattr_init(&mutexattr)){
         printf("error init mutexattr \n");
		 return -1;
	}

	if(pthread_condattr_init(&condattr)){
       printf("error init condattr \n");

	}
	 //把互斥变量属性设置为进程间共享
	if(pthread_mutexattr_setpshared(&mutexattr,PTHREAD_PROCESS_SHARED)){
            printf("error mutexattr set PTHREAD_PROCESS_SHARED\n");
           return -1;
	}

	if(pthread_condattr_setpshared(&condattr,PTHREAD_PROCESS_SHARED)){
         printf("error condattr set PTHREAD_PROCESS_SHARED\n");
         return -1;
	}

	shareinfo->data = 0;
	pthread_mutex_init(&shareinfo->mutex,&mutexattr);
	pthread_cond_init(&shareinfo->cond ,&condattr);
   
	 for(i=1;;i++){
         pthread_mutex_lock(&shareinfo->mutex);
		//if(!shareinfo->data){
            shareinfo->data = i;
            printf("Producer,data set to %d\n",shareinfo->data);
	//	}
        
	//	printf("producer, running i=%d\n",i);

		pthread_cond_broadcast(&shareinfo->cond);
		printf("send a broadcast to notify other process,want to sleep(2) \n");
//		sleep(3);
		pthread_mutex_unlock(&shareinfo->mutex);
	//	pthread_cond_broadcast(&shareinfo->cond);
	//	sleep(2);
	 }

	 if(shm_unlink(SHARE_PATH) <0){
         perror("shm_unlink");
		 return -1;
	 }

	 pthread_mutexattr_destroy(&mutexattr);
	 pthread_condattr_destroy(&condattr);

	 return 0;

}



