<<<<<<< HEAD
#include<netdb.h>
#include"../include/head.h"

int main()
{
	printf("the host : %s\n",gethostent()->h_name);
	printf("the host : %s\n",getnetent()->n_name);
	printf("the server : %s ,port : %d\n",getservent()->s_name,getservent()->s_port);
	
	return 0;
=======
#include <stdlib.h>

int main(int argc,char *argv[])
{
//	gethostbyname
>>>>>>> e17bd0b52f2819249913d19c82bb19f33c3be28c
}
