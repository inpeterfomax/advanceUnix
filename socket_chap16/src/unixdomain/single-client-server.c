#include "head.h"

#define MAXLISTEN 5

int main(int argc,char*argv[])
{
	int fd,size;
	struct sockaddr_un un;
//	memset(&un,0,sizeof(struct sockaddr_un));
	
	un.sun_family = AF_UNIX;
	sprintf(un.sun_path,"unix-domain.socket");	
//	strcpy(un.sun_path,"foo.socket");	
	printf("sizeof struct:%d,pathlen:%d \n",sizeof(struct sockaddr_un),strlen(un.sun_path));
	unlink(un.sun_path);  							//remoe it first

	if( ( fd = socket(AF_UNIX,SOCK_STREAM,0)) == -1){    //creat an endpoint of communication
		perror("create socket failed\n");
		exit(-1);
	}

	size = offsetof( struct sockaddr_un,sun_path ) + strlen( un.sun_path ); //size equals size!
	
	if( bind(fd,(struct sockaddr *)&un,size) == -1){   //bind the fd with the address.
		perror("bind failed");
		exit(0);
	}else{
		printf("server bind done\n");
	}
	
	if( listen(fd,5) == -1){			//wait for the connect require.
		perror("listen failed\n");
		exit(0);
	}
//	pre-work done. then waiting for incoming connect().....
	char tmp, buff[1024];
	int ret,clifd,i,len = sizeof(struct sockaddr_un);
	struct sockaddr_un un_cli;
//	fd set.
	fd_set fdset;
//	process will block on this function.
	if( ( clifd = accept(fd,(struct sockaddr*)&un_cli,&len))< 0 ){ 
		perror("server accept failed\n");
		exit(-1);
	}

	if(clifd > 0){ 
		do{
			i = 0;
			FD_ZERO(&fdset);
			FD_SET(0,&fdset);
			FD_SET(clifd,&fdset); 
//			wait until one of the fds could be used.
			ret = select(clifd+1,&fdset,NULL,NULL,NULL);
			if(ret < 0){
				perror("select failed!\n");
				exit(-1);
			}else if(FD_ISSET(0,&fdset)){
				memset(buff,'\0',sizeof(buff));
				while( (tmp = getchar()) != '\n'){
					buff[i++] = tmp;
				}
				ret = write(clifd,buff,i);
				if(ret != i)
					printf("num do not mach!\n");
			}else if( FD_ISSET(clifd,&fdset)){
				memset(buff,'\0',sizeof(buff));
				ret = read(clifd,buff,128);
				printf("%d\n",ret);
				write(0,buff,ret);
				}
			}while(1);
		}
	return 0;
}
