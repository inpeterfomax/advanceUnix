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
#define PORTNUM 3072

#define FPATH "./receive-file"

#define HELP printf("./serverudp ipaddr \n")
int packetnum = 141089;
int main(int argc,char*argv[])
{
	struct sockaddr_in server,client;
	int sock_fd,child_fd;
	int ret,count=0,count2=0;
	char rdbuff[1024];
	char wrbuff[1024];
	if( argc < 2){
		HELP;
		return -1;
	}
	server.sin_family = AF_INET;
	server.sin_port = htons(PORTNUM);
	printf("ip : %s \n",argv[1]);
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

	char inbuff [512];//bezero at first
	memset(inbuff,0,512);

	int fd = open(FPATH,O_WRONLY|O_TRUNC|O_CREAT|O_APPEND);
	int len=sizeof(struct sockaddr_in);
	int rcvcnt = 17637;
	int rcv = 0;
	while( rcvcnt ){
		rcv = recvfrom(sock_fd,inbuff,sizeof(inbuff),0,(struct sockaddr *)&server,&len);
		count2++;
		write(fd,inbuff,512);			
		memset(inbuff,0,512);
		usleep(20);
		rcvcnt --;		

		printf("rcv : %d rcvcnt :%d \n",rcv,rcvcnt);
	}
	printf("count2 = %d \n",count,count2);
	
	close(fd);
	close(sock_fd);
	
	return 0;
}
