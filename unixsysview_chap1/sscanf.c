#include<stdio.h>
#include<stdlib.h>

int main()
{
	char tmparry[1024]="Hello World!";
	char str1[128] = {0};
	char str2[128] = {0};

	sscanf(tmparry,"%s %s ",str1,str2);
	printf("source=%s , str1=%s ,str2=%s\n",tmparry,str1,str2);
	
	return 0;
}
