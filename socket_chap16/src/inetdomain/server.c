#include"./../include/head.h"
#define SOCKNUM 5
#define PORTNUM 3072

int main()
{
	struct sockaddr_in server,client1;
	int sock_fd,child_fd;
	int ret;
	char rdbuff[1024];
	char wrbuff[1024];

	server.sin_family = AF_INET;
	server.sin_port = htons(PORTNUM);
	server.sin_addr.s_addr =INADDR_ANY;//192.168.182.187;
	bzero(&server.sin_zero,0);

	sock_fd = socket(server.sin_family,SOCK_STREAM,0); 
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
	
	ret = listen(sock_fd,SOCKNUM);
	if(ret == -1){
		perror("listen failed!\n");
		close(sock_fd);
		exit(-1);
	}
	
	int length = sizeof(struct sockaddr);
	char tmpstr[128];
	while(1)
	{
		child_fd = accept(sock_fd,(struct sockaddr*)&client1,&length);
		if(child_fd == -1){
			perror("accept failed!\n");
			close(sock_fd);
			exit(-1);
		}else{
			printf("New Connection :%s\n",inet_ntop(AF_INET,&client1,tmpstr,sizeof(tmpstr)));
		}
		/*child process to do something*/
		ret = fork();
		if( ret < 0){
			perror("fork failed\n!");
			break;
		}else if( ret == 0){	
			send(child_fd,"hello,you've connected\n",sizeof("hello,you've connected\n"),0);
			while( recv(child_fd,rdbuff,512,0))
			{
				printf("receive from client:%s",rdbuff);
			}
			printf("\n");

			close(child_fd);
		}else
			continue;
	}
	waitpid(ret,0,0);
	close(sock_fd);
	
	return 0;
}
