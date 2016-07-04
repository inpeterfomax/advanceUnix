#include<linux/net.h>
#include<sys/types.h>
#include<sys/socket.h>

int main(int argc,char*argv[])
{
	struct sockaddr_un client;
	int sockfd=-1;
	client.sun_family = AF_UNUX;
	sprintf(un.sun_path,"");
	sockfd = socket(AF_UNIX,SOCK_STREAM,0);
	if( sockfd < 0){
		perror("socket\n");return -1;
	}

	
}
