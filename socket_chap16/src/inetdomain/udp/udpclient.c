#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
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

#define PORTNUM 3072

int main(int argc, char*argv[]){
	char* buff;
	int fd ;
	#define FPATH "./videofile"


	
	struct sockaddr_in myaddr,serveraddr;
	memset(&serveraddr,0,sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = PORTNUM;
	myaddr.sin_addr = inet_addr(argv[1]);
	bzero(&serveraddr.sin_zero,0);

	int sock_fd = socket(AF_INET,SOCK_DGRAM,0);

	//int ret = connect(sock_fd,&serveraddr,sizeof(struct sockaddr_in));
	//if( ret < 0)
	//UDP socket no need to do the connect first.
	fd = open(FPATH,O_RDONLY);
	char outbuf[512];

	while( read(fd,outbuf,512) )

	return 0;
}
