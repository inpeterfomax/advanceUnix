#include<stdio.h>
#include<stdlib.h>

int main()
{
	char tmparry[1024]="Hello World  123 !";
	char str1[128] = {0};
	char str2[128] = {0};
	int ai=0;
//sscanf(tmparry," %s %s %d",str1,str2,&ai);
	sscanf(tmparry,"Hello World %d !",&ai);
//	printf("source=%s , str1=%s ,str2=%s ai=%d \n",tmparry,str1,str2,ai);
//	printf("source=%s , str1=%s ,str2=%s ai=%d \n",tmparry,str1,str2,ai);
	printf("source=%s , ai=%d \n",tmparry,ai);
	
	return 0;
}
