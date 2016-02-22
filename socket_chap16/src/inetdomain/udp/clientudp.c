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

#define HELP printf("./clientudp filename ipaddr \n")

#define PORTNUM 3072
//./client filename 192.168.1.110
int main(int argc, char*argv[]){
	char* buff;
	int fd ;
	#define FPATH argv[1]
	if( argc < 2){
		HELP;
		return -1;
	}
	
	struct sockaddr_in addr;
	memset(&addr,0,sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORTNUM);
	printf("ipaddress is %s \n",argv[2]);
	addr.sin_addr.s_addr  = inet_addr(argv[2]);
	bzero(&addr.sin_zero,0);
	
	//const struct sockaddr_in server = addr;
	
	int sock_fd = socket(AF_INET,SOCK_DGRAM,0);
	printf("create udp socket done.\n");
	
	fd = open(FPATH,O_RDONLY);
	printf("open file fd :%d\n",fd);
	char outbuf[512];
	int count = 0;
	int sendcount=0;
	while( read(fd,outbuf,sizeof(outbuf)) ){
		sendcount = sendto(sock_fd,outbuf,sizeof(outbuf),0,(struct sockaddr *)&addr,sizeof(struct sockaddr_in));
		if( sendcount < 0 ){
			printf("send error %d \n",sendcount);
				return -1;
		}
		usleep(20);
		count++;
	}
	
	printf("send %d counts in all\n",count);
	
	shutdown(sock_fd,SHUT_RDWR);
	
	close(fd);
	close(sock_fd);
	
	return 0;
}
