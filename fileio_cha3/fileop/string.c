#include"head.h"

int main()
{
	int value;
	char* p = "ff";

	sscanf("07f2061","%x",&value);
	printf("407f2061:%x\n",value);
	int res = atoi(p);
	printf("atoi:%d\n",res);


	char wifiaddr[128] = {0};
	char *tmpmac = "aabbccddeeffgg";

	sprintf(wifiaddr, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",tmpmac[0],tmpmac[1],'\0',tmpmac[2],tmpmac[3],'\0',tmpmac[4],tmpmac[5],'\0',tmpmac[6],tmpmac[7],'\0',tmpmac[8],tmpmac[9],'\0',tmpmac[10],tmpmac[11]);

	printf("%s\n",wifiaddr);

	printf("%c\n",&wifiaddr[3]);

	printf("%s\n",&wifiaddr[3]);
	printf("%s\n",&wifiaddr[6]);
	printf("%s\n",&wifiaddr[9]);
//	printf("%c\n",wifiaddr[6]);

	return 0;
}
