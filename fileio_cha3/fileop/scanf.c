#include"head.h"

int main()
{
	int temp ;
	int value = 23;
	char charbuf[256];
	char charbuff[256];

	sprintf(charbuf,"%s","please-input-a-integer.\n");   //switch Std-output to charbuf.
	printf("%s",charbuf);
	scanf("%d",&temp);
	sscanf(charbuf,"%s",charbuff);						//switch Std-input to charbuf.
	printf("%s\n",charbuff);
	printf("%s\n",charbuf);

	sscanf(25,"%d",&temp);
	printf("sscanf temp is :%d\n",temp);	

	return 0;
}

#if 0
conclution:
	the 'Enter' key is the end of scanf-like functions' stop.
	the '\0' key is the end of strlen-like functions' stop.

#endif
