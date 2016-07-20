#include<stdio.h>

#define IN 
#define OUT

int func_call(IN int a,OUT int b){
	printf("do %d + %d : ",a,b);
		return a+b;
}

int main(){
	int a=2,b=3;
	printf("%d\n",func_call(a,b));	
	return 0;
}
