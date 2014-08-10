#include<unistd.h> 
#include<stdio.h>
int noname(int a ,int b,int c) 
{
	printf("two parameter:a %d,b%d\n",a,b);
	c = a+b;
	return 0;
}

void havename(void* a)
{
	int b = 10;
	a = &b;
	printf("void parameter,void a=%d\n",(int)&a);
}

void nothing()
{
	printf("this is nothing in parameter\n");
	return;
}

int main(int argc ,char*argv[])
{
	int a=10,b=15,*c;
	void *p; 
	p = &a;
	c = (int *) p;
	printf("c = %d p = %d\n",*c,*((int *)p)); 
	int (*func)(int,int); 
	/*
	void* (*func)();   //任意参数
	func = noname;
	c = *func(a,b);
	printf("c = %d\n",c);
	func = havename;
	func();
	*/
	func = nothing;
	func(a,b);
	#define PATH "./function.c"
	char buff[256];
	FILE *fptr = fopen(PATH,r+);
	if(!fpter)
		printf("open file failed\n");
	while(fread(buff,1,256,fptr) > 0){
		printf("%s\n",buff);
	}

	fclose(fptr);

	return 0;

}
