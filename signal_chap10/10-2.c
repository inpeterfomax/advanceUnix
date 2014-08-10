#include"head.h"

#define NOERR 0

int main()
{
	int ret;

	if( kill(0,SIGUSR1) != NOERR)
		 puts("killerr\n");

	if( kill(0,SIGUSR2) != NOERR)
		puts("killerr\n");

	while(1)
		pause();

	return 0;
}
