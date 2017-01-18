#include<stdio.h>

#define Err(fmt,args...) printf("%d Err "fmt,__LINE__,##args)

int main()
{
	Err("%s","Hello world.\n");


	unsigned int a=10 ,b=20 ,c=30;
	unsigned int d=0,e=0,f=0;

	unsigned char  buff[128]={0};

	sprintf(buff,"%d %d %d",a,b,c);
	//sprintf(buff,"a=%d b=%d c=%d",a,b,c);
	printf("buff= %s\n",buff);
	unsigned int buff_int[128]={12,13,14};
	//sscanf(buff_int,"%d","%d","%d",&d,&e,&f);
//scanf("%d","%d","%d",&d,&e,&f);
	printf("d=%d e=%d f=%d\n",d,e,f);

	sprintf(buff,"Hello world!");
	printf("buff=%s \n",buff);

	char rawdata[512]={};
	char extra[1024] = {0};
	memset(extra,sizeof(extra));
	int i = 0;
	sprintf(extra,"\n0xxx\t");
	for(i=0;i<512;i++){
		sprintf(extra,"%s%02X",extra,rawdata[i]);
		printf("extra:%s\n",extra);
	}

	return 0;
}

