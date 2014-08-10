#include<stdio.h>
#include<stdlib.h>

struct _student{
	char *name;
	int number;
	struct _class{
		char english;
		char chinese;
		char math;
	}std_class;
	int link
};

int main(){
	struct _student stu = {
		.name="peter.gu",
		.number = 10,
		.std_class = {
			.english=1,
			.chinese=2,
			.math=3,
		},
		.link=10,
	};
	//struct _student stu = {"peter.gu",10,{1,2,3},10};
	printf("name %s,number %d,english %d,chinese %d,math %d,link %d",stu.name,stu.number,stu.std_class.english,stu.std_class.chinese,stu.std_class.math,stu.link);
	printf("\n");

	struct _student sta = {0};
	printf("name %s number %d\n",sta.name,sta.number);
	struct _student stb = {NULL};
	printf("name %s number %d\n",stb.name,stb.number);

	return 0;
}



