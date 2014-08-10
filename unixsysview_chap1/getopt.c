//desctiption: use this expamle to illustrate the use of getopt function;
#include<unistd.h> 
#include<stdio.h> 

int main (int argc ,char * argv[]) 
{
	int ret;
	
	while( (ret = getopt(argc,argv,"x:ti:ac:lD"))!= -1){
		switch( ret ){
			case 'x':
				printf("option :x,optarg:%s \n",optarg);
				break;
			case 'i':
				printf("option :i,optarg:%s \n",optarg);
				break;
			case 't':
				printf("option :t , optarg:%s \n",optarg);
				break;
		}
	}
		return 0;
}
