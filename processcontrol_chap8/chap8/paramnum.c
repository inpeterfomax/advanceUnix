#include<stdlib.h>
#include<string.h>

static void print(int arg1,int arg2,int arg3){
	printf("%d%d%d\n",arg1,arg2,arg3);
	exit(0);

}


int main(){
	print(1,2);
	
	return 0;
}
