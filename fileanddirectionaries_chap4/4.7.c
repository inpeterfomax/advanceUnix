#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int
main(int argc, char *argv[])
{
	if (access(argv[1], R_OK) < 0)				//access�Ǽ����̵�real user ID
		printf("access error for %s\n", argv[1]);
	else
        printf("read access OK\n");
	
	if (open(argv[1], O_RDONLY) < 0)			//open�Ǽ����̵�effective user ID
		printf("open error for %s\n", argv[1]);
	else
        printf("open for reading OK\n");
	
	exit(0);

}