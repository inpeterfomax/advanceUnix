#include<sys/socket.h>
#include<sys/un.h>
#include<sys/types.h>
#include<stddef.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<error.h>

#define MAXLEN 1024

int main(int argc,char *argv[])
{
	struct sockaddr_un client;
	memset(&client,0,sizeof(struct sockaddr_un));
	client.sun_family = AF_UNIX;
	sprintf(client.sun_path,"%s_%d","/home/peter/client",getpid());

	int ret;
	int length = offsetof(struct sockaddr_un,sun_path)+strlen(client.sun_path)+1;  //offsetof

	int fd = socket(AF_UNIX,SOCK_STREAM,0);
	if(fd == -1){
		perror("socket failed\n");
		exit(0);
	}
	
	ret = bind(fd,(struct sockaddr_un *)&client,length);//the third patameter means the size if the addr;
	if(ret == -1){
		perror("bind error");
		exit(-1);
	}
	struct sockaddr_un target;
	memset(&target,0,sizeof(struct sockaddr_un));
	target.sun_family = AF_UNIX;
	strncpy(target.sun_path,"/home/peter/server",strlen("/home/peter/server"));

	ret = connect(fd,(struct sockaddr_un *)&target,sizeof(struct sockaddr_un));//the third patameter means the size of the addr;
	if(ret == 0 ){
		perror("connect error");
		exit(-1);
	}

	char buf[MAXLEN];
	int rc;
	while(read(0,buf,sizeof(buf)) > 0){
		if( write(fd,buf,rc) != rc){
			if( rc>0)
				fprintf(stderr,"partical write\n");
			else{
				perror("write failed\n");
				exit(-1 );
			}
		}
	}
	
errors:
	close(fd);

	return 0;
}
