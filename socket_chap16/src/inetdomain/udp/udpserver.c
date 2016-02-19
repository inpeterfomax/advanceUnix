#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<syslog.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<wait.h>
#include<errno.h>
#include<fcntl.h>

#define SOCKNUM 5
#define PORTNUM 3072

int main()
{
	struct sockaddr_in server,client;
	int sock_fd,child_fd;
	int ret;
	char rdbuff[1024];
	char wrbuff[1024];

	server.sin_family = AF_INET;
	server.sin_port = htons(PORTNUM);
	//server.sin_addr.s_addr = INADDR_ANY;//192.168.182.187;
	server.sin_addr.s_addr = inet_addr(argv[1]);//192.168.182.187;
	bzero(&server.sin_zero,0);

	sock_fd = socket(server.sin_family,SOCK_DGRAM,0);// default protocol would be udp.
	if(sock_fd == -1){
		perror("socket failed!\n");
		exit(-1);
	}
	
	ret = bind(sock_fd,(struct sockaddr*)&server,sizeof(struct sockaddr));
	if(ret == -1){
		perror("bind failed!\n");
		close(sock_fd);
		exit(-1);
	}
	
	ret = listen(sock_fd,SOCKNUM);
	if(ret == -1){
		perror("listen failed!\n");
		close(sock_fd);
		exit(-1);
	}
	
	int length = sizeof(struct sockaddr);
	char *buff = calloc(16*1024*1024+1,1);//bezero at first
	
	child_fd = accept(sock_fd,(struct sockaddr*)&client,&length);
	if(child_fd == -1){
		perror("accept failed!\n");
		close(sock_fd);
		exit(-1);
	}else{
		printf("New Connection :%s\n",inet_ntop(AF_INET,&client,buff,sizeof(buff)));
	}
	/*child process to do something*/
	if( ret < 0){
		perror("fork failed\n!");
		break;
	}else if( ret == 0){
	
		while(1){
			recvfrom(child_fd,rdbuff,512,0))
			{
				printf("receive from client:%s",rdbuff);
			}
		}
		printf("\n");

		close(child_fd);
	}

	waitpid(ret,0,0);
	
	close(sock_fd);

	free(buff);
	
	return 0;
}


