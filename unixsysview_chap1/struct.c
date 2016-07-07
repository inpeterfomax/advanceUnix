#include<stdio.h>

struct tmp{
	int a;
	int b:10;	//bit width not initaliation
};
int main()
{
	struct tmp tmpval;
	printf("tmpval:%d\n",tmpval.b);

	return 0;	
}
