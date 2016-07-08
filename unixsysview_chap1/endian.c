#include<stdio.h>

static int is_big_endian(){
	short int tmp = 0x1122;
	char ptr = *(char *)&tmp;
	
	if( ptr == 0x11){
		printf("ptr = 0x%x \n",ptr);
		return 0;
	}else{
		printf("ptr = 0x%x \n",ptr);
		return -1;
	}
	return 1;
}

int main()
{
	if( is_big_endian() != 0){
		printf(" little endian\n");
	}else
		printf(" big endian\n");

	return 0;
}
