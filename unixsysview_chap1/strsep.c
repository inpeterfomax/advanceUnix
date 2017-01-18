#include<stdio.h>
#include<string.h>

int main()
{
	char *ptr = strdup("hello,ladies,gentlemen,welcom,to,the,new,world!");
	char *ppp = ",";
	char *p=NULL;
	//printf("%s \n",strsep(&ptr,ppp));
	while( p=strsep(&ptr,ppp))
	{
		printf("%s\n",p);	 
	}
	return 0;
}
