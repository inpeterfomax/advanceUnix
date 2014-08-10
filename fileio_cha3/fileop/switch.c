#include"head.h"

int main(void)
{
	int a;
	scanf("%d",&a);

	switch(a)
	{
		case 1:
			printf("1");
			break;
		case 2:
		case 3:
			printf("2");
			break;
	
		default:
			printf("4");
			
	}

	return 0;
}

