/*
	Input to string number (maxinum 100 numbers), and return the a-b value;
	1. - in the first string fornt or the second string front.
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/**/
#define INPUTSIZE 100

static void plus(int *numstr1,int len1,int* numstr2,int len2,char*result)
{
	int h=0,i=len1-1,j=len2-1;
	int tmp[INPUTSIZE];
	for(i,j;i>0,j>0;i--,j--){
		
	}
}
static void makeint(char*inputstr,int a[],int b[]){
	int asym=1,bsym=1;
	int i,j,k;

	for( i=0; inputstr[i]!='\0'; i++ ){
		if( i == 0 && inputstr[i] == '-' ){
			asym = -1;
			k = 0;
			continue;
		}else if( inputstr[i] != ' '){
			a[k++] = inputstr[i] - '0';
			continue;
		}else if( inputstr[i] == ' '){
			j=i+1;
			b[j++]=inputstr[j++]
			continue;
		}
	
			
		
	}
}
static bool okformat(const char*input,int len)
{
	if ( NULL == input )
		return false;

	int i,nonius=0,_count=0;
	int secondstr=0;
	for( i = 0;i < len; i++ ){
		if( input[i] == '-' && i == 0)
			continue;
			
//		if( input[i] > '0' && input[i] < '9' )
//			continue;
		if( secondstr == 0 ){
			if( input[i] > '0' && input[i] < '9' )
				continue;
			else if( input[i] == ' ' ){	// the second sub.
				secondstr = i+1;		// the second negative string.
				continue;
			}else
				break;
		}else{
			if( input[secondstr] == '-' && secondstr == i )
				continue;
			if( input[i] > '0' && input[i] < '9' )
				continue;
			else
				break;
		}	
	}
	if( i == len)
		return true;
	else
		return false;
}

int main(int argc,char *argv[])
{
	printf("please input the needed string\n");
	char buf[200]={0};
	int len;
	
	gets(buf);
	len = strlen(buf);

	if( !okformat(buf,len) ){
		printf("input string error\n");
		return -1;
	}

	
}
