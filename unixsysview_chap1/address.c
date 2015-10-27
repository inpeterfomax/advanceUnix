#include<stdio.h>

static const char valuetmp[]={'a','b','c','d','e','f','g','h','i','j'};


void show(unsigned long address)
{
	char*tmpp=NULL;
	tmpp = (char *)address;//make it's type clear.
	tmpp += 0x00000001;
	printf(" line:%d show value=%c \n",__LINE__,*tmpp);
}

void showvalue(char startele[])
{
	char *ptr=startele[0];
	printf("show value of ptr address %ld ,startele address %ld \n",ptr,&startele[0]);
	
	return;
}

void showaddress(const char arrytmp[],const int elenum)
{
	unsigned long tmpaddr=0x00000000;
	printf("start and end address of tmparry is start=%ld,end=%ld \n",&arrytmp[0],&arrytmp[elenum-1]);
	tmpaddr=(unsigned long)&arrytmp[0];
	tmpaddr+=0x00000001;
	printf("start address + 0x00000001 equals %ld,it's value equals %c \n",tmpaddr,*(char *)tmpaddr);
	show(tmpaddr);
}

int main(int argc,char*argv[])
{
	showaddress(valuetmp,sizeof(valuetmp));

	return 0;
}
