#include<pthread.h>
#include<unistd.h>
#include<stdio.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h> 
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/un.h>
#include <sys/wait.h>

#include <poll.h>

#define MAXLISTEN 5

#define OPEN_MAX 128

typedef struct __hello{
	int a;
	int c;
	char *b;
	void *d;
}mytype;

void* thread_fun_srv_1(void *a)
{
/*	
	mytype *tmp = (mytype *)a;
	while(1)
		printf("this is function %s tmp->a:%d\n",__func__,tmp->a);
*/
	printf("%s %d thread 1 run....\n",__func__,__LINE__);
	int listenfd,size;
	struct sockaddr_un un;

	size = offsetof( struct sockaddr_un,sun_path) + strlen(un.sun_path); //size equals size!
	memset(&un,0,sizeof(struct sockaddr_un));
	
	un.sun_family = AF_UNIX;  //unix domain socket. processes in the same system.socket(domain,type,protocol)

	sprintf(un.sun_path,"./unix-domain-%d",getpid());
	unlink(un.sun_path);  							//remoe it first

	if( ( listenfd = socket(AF_UNIX,SOCK_STREAM,0)) == -1){    //creat an endpoint of communication
		perror("create socket failed\n");
		exit(-1);
	}
	if( bind( listenfd,(struct sockaddr *)&un,size) == -1){   //bind the fd with the address.
		perror("bind failed\n");
		exit(0);
	}
	
	if( listen(listenfd,MAXLISTEN) == -1){			//wait for the connect require.
		perror("listen failed\n");
		exit(0);
	}
	printf("%s %d after listen\n",__func__,__LINE__);
	//fd operation....
	fd_set fdset;
	FD_ZERO(&fdset);
	int ret,clifd,num;
	char  buf[1024];
	int len = sizeof(struct sockaddr_un);
	struct sockaddr_un un_cli;
	int fdqueue[MAXLISTEN];
	
	if( (clifd = accept(listenfd,(struct sockaddr*)&un_cli,&len)) <0 ){ //what's the work fo len;
		printf("server accept failed\n");
		exit(-1);
	}else if(clifd > 0){
		printf("accept success , pid=%d\n",getpid());
	}else if( ret== 0){
		//num = write(clifd,"123456",6); 
		//if(num != 6)	
			//printf("write failed!\n");	
		//ret =100;
	}else{
		printf("test if parences param changed by child.ret:%d\n",ret);
		waitpid(clifd,&ret,0);
	}
	printf("%s %d after accept\n",__func__,__LINE__);

	struct  pollfd clientfds[OPEN_MAX];
	//Ìí¼Ó¼àÌýÃèÊö·û
	clientfds[0].fd = listenfd;
	clientfds[0].events = POLLIN;
	
	printf("before poll function\n");

	poll(clientfds,3+1,-1);

	printf("aftter poll function\n");
	
	pthread_exit((void*)0);

}

void* thread_fun_srv_2(void* a)
{
/*
	mytype *tmp = (mytype *)a;
	while(1)
		printf("this is function %s tmp->a:%d\n",__func__,tmp->a);
*/	
	printf("%s %d thread 2 run....\n",__func__,__LINE__);

	int listenfd,size;
	struct sockaddr_un un;

	size = offsetof( struct sockaddr_un,sun_path) + strlen(un.sun_path); //size equals size!
	memset(&un,0,sizeof(struct sockaddr_un));
	
	un.sun_family = AF_UNIX;  //unix domain socket. processes in the same system.socket(domain,type,protocol)

	sprintf(un.sun_path,"./unix-domain-%d",getpid()+6);
	unlink(un.sun_path);  							//remoe it first

	if( ( listenfd = socket(AF_UNIX,SOCK_STREAM,0)) == -1){    //creat an endpoint of communication
		perror("create socket failed\n");
		exit(-1);
	}
	if( bind( listenfd,(struct sockaddr *)&un,size) == -1){   //bind the fd with the address.
		perror("bind failed\n");
		exit(0);
	}
	
	if( listen(listenfd,MAXLISTEN) == -1){			//wait for the connect require.
		perror("listen failed\n");
		exit(0);
	}
	
	printf("%s %d after listen\n",__func__,__LINE__);

	//fd operation....
	fd_set fdset;
	FD_ZERO(&fdset);
	int ret,clifd,num;
	char  buf[1024];
	int len = sizeof(struct sockaddr_un);
	struct sockaddr_un un_cli;
	int fdqueue[MAXLISTEN];
	
	printf("%s %d before accept\n",__func__,__LINE__);

	if( (clifd = accept(listenfd,(struct sockaddr*)&un_cli,&len)) <0 ){ //what's the work fo len;
		printf("server accept failed\n");
		exit(-1);
	}

	printf("%s %d after accept\n",__func__,__LINE__);

	struct  pollfd clientfds[OPEN_MAX];
	//Ìí¼Ó¼àÌýÃèÊö·û
	clientfds[0].fd = listenfd;
	clientfds[0].events = POLLIN;
	
	printf("before poll function\n");

	poll(clientfds,3+1,-1);

	printf("aftter poll function\n");

	pthread_exit((void*)0);

}

int main()
{
	int ret;
	pthread_t pthread1,pthread2;
	mytype a={1,2,NULL,NULL};

	ret = pthread_create(&pthread1,NULL,thread_fun_srv_1,NULL);
	if(ret != 0 ){
		printf("create thread-1 filed +++++++++++\n");
	}else
		printf("create thread-1 success +++++++++++\n");
	ret = pthread_create(&pthread1,NULL,thread_fun_srv_2,NULL);
	if(ret != 0 ){
		printf("create thread-2 filed ----------\n");
	}else
		printf("create thread-2 success +++++++++++\n");

	printf("%s %d \n",__func__,__LINE__);

	pthread_join(pthread1,NULL);
	pthread_join(pthread2,NULL);
	
	printf("%s %d \n",__func__,__LINE__);

	//pause();//means the main thead to suspend.
	//	while(1);
}
