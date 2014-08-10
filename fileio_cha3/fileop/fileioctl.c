#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
	int cmd = 1;
	int arg = 2;
	int fd = open("/dev/test",O_RDONLY);
	
	if( fd < 0)
	{
		printf("open file failed\n");
		return 0;
	}
	
	ioctl(fd,cmd,arg);
	
	return 0;
}