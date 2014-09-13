#include <stdio.h> 
#include <string.h> 
#include <sys/types.h> 
#include <error.h> 
#include <errno.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <fcntl.h> 
#include <unistd.h> 
 
#define BUF_SIZE 30 
 
int main(int argc,char *argv)
{ 
    int s[2]; 
    int w,r,ret; 
    static char * string = "This is a test string"; 
    char * buf = (char*)calloc(1 , BUF_SIZE); 

    if( socketpair(AF_UNIX,SOCK_STREAM,0,s) == -1 ){ 
		printf("create unnamed socket pair failed:%s\n",strerror(errno) ); 
        exit(-1); 
    } 
	
	ret = fcntl(s[0],F_SETFD,O_NONBLOCK);	
    /*******test in a single process ********/ 
    if( ( w = write(s[0] , string , strlen(string) ) ) == -1 ){ 
        printf("Write socket error:%s\n",strerror(errno)); 
        exit(-1); 
    } 
    /*****read*its like a pipe******/ 
    if( (r = read(s[1], buf , BUF_SIZE )) == -1){ 
            printf("Read from socket error:%s\n",strerror(errno) ); 
            exit(-1); 
    }else
		printf("Read string in same process : %s \n",buf);
#if 1
  	if( ( r = read(s[0], buf , BUF_SIZE )) == -1 ){ 
          printf("Read from socket s0 error:%s\n",strerror(errno) ); 
          exit(-1); 
  	} else
  		printf("Read from s0 :%s\n",buf); 
	
	/*now this process has been in state:interruptable sleep,it waiting for an enent to complete*/
#endif
    printf("Test successed\n"); 

	exit(0); 
} 
