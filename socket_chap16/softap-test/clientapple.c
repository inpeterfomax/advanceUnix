#include<unistd.h>  //for STDIN_FILENO
#include<fcntl.h> //for set/get_fl; fcntl....
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<syslog.h> //for syslog
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>			//this i can treat as the database

#include<wait.h>

#include<errno.h>
#include<fcntl.h>
#define PORTNUM 3072

int main(int argc,char *argv[])
{
	int fd;
	int ret;
	int length;

	struct sockaddr_in server;
	
	
	if( argc < 2){
		perror("please provide hostaddress!\n");
		exit(-1);
	}

	server.sin_family = AF_INET;	
	server.sin_port = htons(PORTNUM);
	server.sin_addr.s_addr =inet_addr(argv[1]);
	bzero(&server.sin_zero,0);

	fd = socket(AF_INET,SOCK_STREAM,0);
	if(fd == -1){
		perror("socket failed!\n");
		exit(-1);
	}


	length = sizeof(struct sockaddr);
	ret = connect(fd,(struct sockaddr*)&server,length);
	if(ret == -1){
		perror("connect failed!\n");	
		close(fd);
		exit(-1);
	}else{
		printf("connect to server %s\n",argv[1]);
		send(fd,"it's client1\n",256,0);
	}
	
	close(fd);
	
	return 0;	                              	
}
