#include "head.h"
#define SERVERSUNPATH "unix-domain.socket"

int main(int argc , char *argv[])
{
	int fd,size,size_ser;
	struct sockaddr_un un , server;
/*	
	if( argc < 2) {
		printf("server name needed!\n");
		exit(0);
	}
*/	
	memset(&un,0,sizeof(struct sockaddr_un));
	un.sun_family = AF_UNIX;
	sprintf(un.sun_path,"%s-%d","client",getpid());
	unlink(un.sun_path); //in case this file has been there ;for it must be created by the bind;
	
	if( ( fd = socket(AF_UNIX,SOCK_STREAM,0)) < 0){
		perror("create socket failed\n");
		exit(1);
	}
	/*
		bind ; use  the common file as the addr.un_addr;
	*/

	memset(&server,0,sizeof(struct sockaddr_un));
	server.sun_family = AF_UNIX;
	if( argv[1])
		strcpy(server.sun_path,argv[1]);	//command-line param
	else
		strcpy(server.sun_path,"unix-domain.socket");	//default one

	size_ser = offsetof(struct sockaddr_un,sun_path) + sizeof(server.sun_path); 

	if( connect(fd ,(const struct sockaddr*)&server,size_ser)){
		perror("connect server failed\n");
		exit(1);
	} 

	fd_set fdset;
	char buff[128] ;
	int num,ret,i=0; 
	char tmp;
	
	while(1)
	{
		FD_ZERO(&fdset);
		FD_SET(0,&fdset);
		FD_SET(fd,&fdset);
		
		ret = select(fd+1,&fdset,NULL,NULL,NULL);
		if( ret < 0 ){
			perror("select failed !\n");
			exit(-1);
		}else if( FD_ISSET(0,&fdset)){
//			get message from stdin & wirte to fd
			memset(buff,'\0',128);
			while( (tmp = getchar()) != '\n'){
				buff[i++] = tmp;
			}
			num = write(fd,buff,i);
			printf("write %d char into fd :%s\n",num,buff);
			if(num != i)
				printf("do not match !\n");
			i = 0,num = 0;
		}else if(FD_ISSET(fd,&fdset)){
			memset(buff,'\0',128);
//			get message from server & output to stdin
			while( ( num = read(fd,buff,128)) > 0 ){
				write(0,buff,num);
				putchar('\n');
			}
		}
	};
	return 0;
}
