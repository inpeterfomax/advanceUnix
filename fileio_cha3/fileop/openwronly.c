#include"head.h"

int main()
{
	int fd = open("./hello.txt",O_WRONLY);
	char buff[16]={'0'};

	int ret = read(fd,buff,4);

	printf("read result:%d,%s\n",ret,buff);

	return;
}
