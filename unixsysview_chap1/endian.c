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

//data stored in union from low address.

static int is_little_endian()
{
	union untype{
		char a;
		int b;
	}c;
	c.b = 0x1122;
	printf("c.b = 0x%x \n",c.b);
	if( c.a == 0x22)
	{
		printf("little endian \n");
	}else if( c.a == 0x11){
		printf("big endian \n");
	}else
		printf("wrong...\n");

	return 0;
}
int main()
{
	if( is_big_endian() != 0){
		printf(" little endian\n");
	}else
		printf(" big endian\n");
	// union to judge if cpu in little-big endian;
	is_little_endian();

	return 0;
}
