#include"client_data.h"
#include"client_api.h"


int main(int argc, char*argv[])
{
	int ret;
	pthread_t pthid_1,pthid_2;
	void *thread_result;
	
	initial_socket_semaphore(&mydata.read_write_semaphore);
	ret = sock_connect(mydata.client_sockfd,SOCKNUM);
	if(ret != 0)
		perror("scok_connect:");
#ifdef DEBUG
	printf("11111\n");
#endif
	ret = pthread_create(&pthid_1,NULL,write_sock_func,&mydata.client_sockfd[0]);
	if( ret != 0)
		perror("pthread_create:");

#ifdef DEBUG
		printf("2222\n");
#endif	
	ret = pthread_create(&pthid_2,NULL,read_sock_func,&mydata.client_sockfd[1]);
	if( ret != 0)
		perror("pthread_create:");

#ifdef DEBUG
		printf("3333\n");
#endif


	pthread_join(pthid_1,NULL);
	pthread_join(pthid_2,NULL);

#ifdef DEBUG
		printf("really bad!\n");
#endif

sock:
	destroy_socket_semaphore(&mydata.read_write_semaphore);
		
	return 0;
}
