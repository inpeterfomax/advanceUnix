#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h> 
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/un.h>
#include <sys/wait.h>

#define MAXLISTEN 5

int main(int argc,char*argv[])
{
	int fd,size;
	struct sockaddr_un un;

	size = offsetof( struct sockaddr_un,sun_path) + strlen(un.sun_path); //size equals size!
	memset(&un,0,sizeof(struct sockaddr_un));
	
	un.sun_family = AF_UNIX;  //unix domain socket. processes in the same system.socket(domain,type,protocol)

	sprintf(un.sun_path,"./unix-domain-%d",getpid());
	unlink(un.sun_path);  							//remoe it first

	if( ( fd = socket(AF_UNIX,SOCK_STREAM,0)) == -1){    //creat an endpoint of communication
		perror("create socket failed\n");
		exit(-1);
	}

	if( bind( fd,(struct sockaddr *)&un,size) == -1){   //bind the fd with the address.
		perror("bind failed\n");
		exit(0);
	}
	
	if( listen(fd,MAXLISTEN) == -1){			//wait for the connect require.
		perror("listen failed\n");
		exit(0);
	}

	//fd operation....
	fd_set fdset;
	FD_ZERO(&fdset);
	int ret,clifd,num;
	char  buf[1024];
	int len = sizeof(struct sockaddr_un);
	struct sockaddr_un un_cli;
	int fdqueue[MAXLISTEN];
	
	if( (clifd = accept(fd,(struct sockaddr*)&un_cli,&len))<0 ){ //what's the work fo len;
		printf("server accept failed\n");
		exit(-1);
	}else if(clifd > 0){ 
		if(	ret = fork() < 0){
			printf("fork failed!\n");
			exit(-1);
		}else if( ret== 0){
			num = write(clifd,"123456",6); 
			if(num != 6)	
				printf("write failed!\n");	
			ret =100;
		}else{
			printf("test if parences param changed by child.ret:%d\n",ret);
			waitpid(clifd,&ret,0);
		}
	}
	return 0;
}
