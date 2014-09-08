#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h> 
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/un.h>

#define MAXLISTEN 5

int main(int argc,char*argv[])
{
	int fd,size;
	struct sockaddr_un un;

	size = offsetof( struct sockaddr_un,sun_path) + strlen(un.sun_path); //size equals size!
	memset(&un,0,sizeof(struct sockaddr_un));
	
	un.sun_family = AF_UNIX;
	strcpy(un.sun_path,"unix-domain");
	unlink(un.sun_path);  							//remoe it first

	if( ( fd = socket(AF_UNIX,SOCK_STREAM,0)) == -1){    //creat an endpoint of communication
		perror("create socket failed\n");
		exit(-1);
	}

	if( bind( fd,(struct sockaddr *)&un,size) == -1){   //bind the fd with the address.
		perror("bind failed\n");
		exit(0);
	}else{
		printf("server bind done\n");
	}
	
	if( listen(fd,5) == -1){			//wait for the connect require.
		perror("listen failed\n");
		exit(0);
	}
#if 0
	char tmp, buff[1024];
	int ret,clifd,i;
	int len = sizeof(struct sockaddr_un);
	struct sockaddr_un un_cli;

	fd_set fdset;
	
	if( ( clifd = accept(fd,(struct sockaddr*)&un_cli,&len))< 0 ){ 
		printf("server accept failed\n");
		return 0;
	}else if(clifd > 0){ 
		
		while(1)
		{
			i = 0;
			FD_ZERO(&fdset);
			FD_SET(0,&fdset);
			FD_SET(clifd,&fdset); 

			ret = select(clifd+1,&fdset,NULL,NULL,NULL);	//wait until one fd could be used.
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
			}
		}
#endif
	return 0;
}
