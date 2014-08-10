#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h> 
#include<unistd.h> 

char buf[500000];

extern void set_fl(int,int);
extern void clr_fl(int,int);

int main(void)
{
	int ntowrite,nwrite;
	char *ptr;
	
	ntowrite = read(STDIN_FILENO,buf,sizeof(buf));
	fprintf(stderr,"read %d bytes\n",ntowrite); //stderr is FILE* type STDERR_FILENO = ptof(stderr); ?

	set_fl(STDOUT_FILENO,O_NONBLOCK); 
	
	ptr = buf;
	while(nwrite > 0){
		errno = 0;
		nwrite = write(STDOUT_FILENO,ptr,ntowrite); 
		fprintf(stderr,"nwrite = %d ,errno = %d\n",nwrite,errno); 
		
		if(nwrite >0){
			ptr += nwrite;
			ntowrite -= nwrite;
		}
	}
	clr_fl(STDOUT_FILENO,O_NONBLOCK); 

	exit(0);
}
