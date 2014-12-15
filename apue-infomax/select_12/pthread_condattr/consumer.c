#include"common.h"
int main(void){
   int fd;
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
   if (shareinfo < 0) {
		        perror("mmap");
		          return -1;
		      }

   close(fd);


   while(1){
       pthread_mutex_lock(&shareinfo->mutex);
	  #if 1
		   while (shareinfo->data) {
			   printf("consumer, data:%d\n", shareinfo->data);
	           pthread_cond_wait(&shareinfo->cond, &shareinfo->mutex);
			    break;
		 }
		#endif
	    printf("consumer, cleaning data:%d\n", shareinfo->data);
        pthread_mutex_unlock(&shareinfo->mutex);
       //sleep(2);
   }
    if (shm_unlink(SHARE_PATH) < 0) {
        perror("shm_unlink");
		return -1;
	   }

  return 0;
 
}
