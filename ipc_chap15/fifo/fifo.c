#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
#include<fcntl.h>  
#include<sys/types.h>  
#include<sys/stat.h>  

#define PATH "/tmp/fifo"

int main(int argc,char *argv[])  
{  
    int fd;  
    char buf[20] = "hello world!!!/n";  
	char buff[128];
	if( ret=fork() < 0)
	{
		perror("fork faild\n");
		exit(-1);
	}else if(ret > 0)
	{

    	if((mkfifo("my_fifo", O_CREAT|O_RDWR|0666)) < 0)  
    	{  
        	perror("mkfifo");  
        	exit(1);  
    	}  
    	if((fd = open("my_fifo" , O_WRONLY)) < 0)  
    	{  
    	    perror("open");  
    	    exit(1);  
   		 }  
    	if((write(fd,buf,strlen(buf)-1)) < 0)  
    	{  
    	    perror("write");  
    	    exit(1);  
   		} 
	}else if( ret == 0)
	{

	}
	waitpid(ret,NULL,0); 
    return 0;  
              
} 
