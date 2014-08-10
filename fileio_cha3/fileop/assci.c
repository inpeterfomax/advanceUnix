#include"head.h"

int main()
{
	char a = '0';  //0x31  48

	printf("2*a : %d %x \n",a*2,a*2);	

//	char b = 'a'*16 + 'b';

//	printf("'a'*16+'b'=%c",b);

//	unsigned int c ;
	unsigned char value;

	sscanf("ab","%x",&value);
	
	printf("%x\n",value);
/*	
	unsigned char b = 0xff;
	printf("%x\n",b);
	printf("%d\n",b);
	printf("%c\n",b);
*/
	return 0;
}
