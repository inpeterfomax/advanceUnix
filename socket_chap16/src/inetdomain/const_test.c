#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
	int id;
	char name[10];
};


int main()
{
	const int a = 4;
	const int b;
	const struct student jack={10,"jack"};
	/*jack.id=10;
	strcpy(jack.name,"jack");*/

	printf("a=%d,b=%d\n",a,(int)b);
	printf("jack:id=%d,name:%s\n",jack.id,jack.name);

	return 0;
}
