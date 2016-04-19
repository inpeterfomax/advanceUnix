#include<stdio.h>
#include<stdlib.h>

struct contents {
	int a;
	int b;
};

struct list{
	struct contents a;
	struct list *next;
};

int main(int argc,char*argv[])
{
	struct list mylist={10,20,NULL};
	
	printf("mylist contents : %d %d %p \n",mylist.a,mylist.a.b,mylist.next);

	return 0;
}
