#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



#define FILENAME "/dev/tranceiver" 
#define ERRNO (-1)

int main(int argc,char *argv[]){
	int fd = 0;

	fd = open(FILENAME,O_RDWR);
	if( fd < 0){
		printf("open failed\n");
		return ERRNO;
	}
/*
	while(1){
		ioctl(fd,wait-cmd,arg);
		
		ioctl(fd,get-cmd,arg);
	}
*/
	printf("%s %d \n",__FUNCTION__,__LINE__);

	close(fd);
	
	return 0;
}

