#include<stdio.h>
#include<unistd.h> 

enum types { SLEEP=0,STOP, RECVING};
int tmp=12;
static int hello;

int main()
{
	enum types a=STOP;
	printf("%d\n",a);

	return 0;
}
