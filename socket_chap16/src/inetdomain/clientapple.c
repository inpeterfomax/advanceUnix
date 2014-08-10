#include"../include/head.h"

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
	server.sin_port = htons(3072);
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
