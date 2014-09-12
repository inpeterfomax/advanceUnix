#include<netdb.h>
#include"../include/head.h"

int main()
{
	printf("the host : %s\n",gethostent()->h_name);
	printf("the host : %s\n",getnetent()->n_name);
	printf("the server : %s ,port : %d\n",getservent()->s_name,getservent()->s_port);
	
	return 0;
}
