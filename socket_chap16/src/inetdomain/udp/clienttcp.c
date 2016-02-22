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
//#include<wait.h>
#include<errno.h>
#include<fcntl.h>

#define HELP printf("./clientudp ipaddr \n")

#define PORTNUM 5072
int main(int argc, char*argv[])
{
	char* buff;
	int fd ,ret;
	#define FPATH argv[1]
	
	struct sockaddr_in addr;
	memset(&addr,0,sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORTNUM);
	printf("ipaddress is %s \n",argv[1]);
	addr.sin_addr.s_addr  = inet_addr(argv[1]);
	bzero(&addr.sin_zero,0);
		
	int sock_fd = socket(AF_INET,SOCK_STREAM,0);
	printf("create stream socket done.\n");

	ret = connect(sock_fd,(struct sockaddr *)&addr,sizeof(struct sockaddr_in));
	if( ret < 0){
		printf("connect ...%d \n",ret);
		return -1;
	}
	char outbuf[64]="Hello Tiger";
	int count = 0;
	int sendcount=0;

	sendcount = send(sock_fd,outbuf,sizeof(outbuf),0);
	if( sendcount < 0 ){
		printf("send error %d \n",sendcount);
			return -1;
	}
	
	close(sock_fd);
	
	return 0;
}
