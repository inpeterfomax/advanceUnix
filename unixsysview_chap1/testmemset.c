#include<stdio.h>
#include<string.h>

int main()
{
#if 0
	//char prtString[128]="IFACE=wlan0 SET_NETWORK 12 ssid aa:vv:cc:dd:dd:ee";
	char* prtString="IFACE=wlan0 SET_NETWORK 12 ssid aa:vv:cc:dd:dd:ee";
	char* subString=strstr(prtString,"ssid");
	
	memset(subString,0,strlen(subString));//only prtString is declared as an arry . we can do this operation.
	printf("the left sting %s  without %s \n",prtString,subString);
#endif
	char* cmd="this is 2 number!";
	int id ;
	id = atoi(cmd);
	printf("cmd %s id %d \n",cmd,id);

	
	return 0;
}
