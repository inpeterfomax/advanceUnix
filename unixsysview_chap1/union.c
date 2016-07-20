
#include<stdio.h>

int main()
{
	union _a{
		int b;
		char d;
		char c;
	}a;

	a.b = 0x1122;
	printf("a.d = 0x%x , a.c = 0x%x\n",a.d,a.c);

	return 0;
}
