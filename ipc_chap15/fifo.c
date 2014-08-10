#include<stdlib.h>
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	int ret,fd;
	ret = mkfifo("/tmp/key",0777);
	if(ret < 0){
		printf("mkfifo failed\n");
		return -1;
	}
	
	fd = open("/tmp/key",O_RDONLY|O_NONBLOCK);   //cant not O_RDWR
	printf("open done,fd:%d\n",fd);
	if(fd < 0){
		printf("open failed\n");
		return -1;
	}
	return 0;
}
