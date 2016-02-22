#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>

#define SERV_PORT   3000
  
int main()
{
    int sock_fd;
    int recv_num;
    int send_num;
    int client_len;
    char recv_buf[20];
    struct sockaddr_in  addr_serv;
    struct sockaddr_in  addr_client;
    sock_fd = socket(AF_INET,SOCK_DGRAM,0);
    if(sock_fd < 0){
            perror("socket");
            exit(1);
    } else{

            printf("sock sucessful\n");
    }

    memset(&addr_serv,0,sizeof(struct sockaddr_in));
    addr_serv.sin_family = AF_INET;
    addr_serv.sin_port = htons(SERV_PORT);
    addr_serv.sin_addr.s_addr = htonl(INADDR_ANY);

    client_len = sizeof(struct sockaddr_in);

    if(bind(sock_fd,(struct sockaddr *)&addr_serv,sizeof(struct sockaddr_in))<0 ){
            perror("bind");
            exit(1);
    } else{

            printf("bind sucess\n");
    }
    while(1){
            printf("begin recv:\n");
            recv_num = recvfrom(sock_fd,recv_buf,sizeof(recv_buf),0,(struct sockaddr *)&addr_client,&client_len);
            if(recv_num <  0){
                    printf("bad\n");
                    perror("again recvfrom");
                    exit(1);
            } else{
                    recv_buf[recv_num]='\0';
                    printf("recv sucess:%s\n",recv_buf);
            }
            printf("begin send:\n");
            send_num = sendto(sock_fd,recv_buf,recv_num,0,(struct sockaddr *)&addr_client,client_len);
            if(send_num < 0){
                    perror("sendto");
                    exit(1);
            } else{
                    printf("send sucessful\n");
            }
    }
    close(sock_fd);
    return 0;
}
