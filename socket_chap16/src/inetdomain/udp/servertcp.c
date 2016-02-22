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
//#include<wait.h>
#include<errno.h>
#include<fcntl.h>

#define SOCKNUM 5
#define PORTNUM 5072

#define HELP printf("./serverudp ipaddr \n")
int main(int argc,char*argv[])
{
	struct sockaddr_in server,client;
	int sock_fd,child_fd;
	int ret,count=0,count2=0;
	char rdbuff[1024];
	char wrbuff[1024];
	//if( argc < 2){
		//HELP;
		//return -1;
	//}
	server.sin_family = AF_INET;
	server.sin_port = htons(PORTNUM);
	server.sin_addr.s_addr = INADDR_ANY;//192.168.182.187;
	//printf("ip : %s \n",argv[1]);
	//server.sin_addr.s_addr = inet_addr(argv[1]);//192.168.182.187;
	bzero(&server.sin_zero,0);

	sock_fd = socket(server.sin_family,SOCK_STREAM,0);// default protocol would be udp.
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
	
	ret = listen(sock_fd,5);
	if( ret < 0 ){
		printf("listen ...\n");
		return -1;
	}
	int sock_client = -1;
	
	char inbuff [64];//bezero at first
	memset(inbuff,0,512);
	printf("%s %d\n",__func__,__LINE__);
	int len = sizeof(struct sockaddr_in);
	if( sock_client = accept(sock_fd,(struct sockaddr*)&client,(socklen_t *)&len )){
		printf("sock_client %d \n",sock_client);

		while( 1){
			ret = recv(sock_client,inbuff,sizeof(inbuff),0);
			if( ret < 0){
				printf("recv ...\n");exit(-1);
			}else
				printf("recv : \" %s \" from client \n",inbuff);
		}
#if 0
	while(1){
		ret = recvfrom(sock_fd,inbuff,sizeof(inbuff),0,(struct sockaddr *)&server,&len);
		count++;
		if(ret < 0){
			printf("recv error %d \n",ret);
			return -1;
		}else
			printf("recv from client %d \n",count);
		if( strlen(inbuff) > 0 ){
			count2++;

			write(fd,inbuff,512);			

			memset(inbuff,0,512);
		}
	}
	printf("count = %d count2 = %d \n",count,count2);
#endif
	}
	close(sock_client);
	close(sock_fd);
	
	return 0;
}
