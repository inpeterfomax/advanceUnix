#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>


int main()
{
	int fd;
	fd = open("./test.txt",O_RDONLY);
	if(fd == -1){
		printf("err open , errno=%d \n",errno);	
	}

	return 0;
}

