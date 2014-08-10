#include <stdio.h>


int main()
{
	char host[255];

	gethostname(host,255);
	printf("%s\n",host);
	return 0;
}
