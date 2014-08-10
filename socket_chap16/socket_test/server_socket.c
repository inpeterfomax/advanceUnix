#include<sys/socket.h>
#include<sys/un.h>
#include<sys/types.h>
#include<stddef.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<error.h>

#include<pthread.h>

#define SOCK_LIST 5

void* call_back(void){
	printf("this is call_back_1");
}

int main(int argc,char *argv[])
{
	struct sockaddr_un server ;
	memset(&server,0,sizeof(struct sockaddr_un));
	server.sun_family = AF_UNIX;
	strncpy(server.sun_path,"/home/peter/server",strlen("/home/peter/server"));

	int ret;
	//int length = offsetof(struct sockaddr_un,sun_path)+strlen(client.sun_path);  //offsetof

	int fd = socket(AF_UNIX,SOCK_STREAM,0);
	if(fd == -1){
		perror("socket failed\n");
		exit(0);
	}
	
	ret = bind(fd,(struct sockaddr_un *)&server,sizeof(struct sockaddr_un)) ; //pay attention to the third paragrame
	if(ret < 0 ){
		perror("bind error");
		goto errors;
	}
	
	listen(fd,SOCK_LIST);
	printf("listen success\n");

	int tmp;
	pthread_t tpid;
	socklen_t addrlen;
	struct sockaddr_un client;
	memset(&client,0,sizeof(struct sockaddr_un));

	while(1)
	{
		tmp = accept(fd,(struct sockaddr_un *)&client,&addrlen);          //pay attention to the third patameter,it reveives;
		if(tmp == -1){
			printf("accept failed ,continue!");
			continue;
		}
		else{
			printf("you are %s\n",client.sun_path);
		}
	}


errors:
	close(fd);

	return 0;
}
