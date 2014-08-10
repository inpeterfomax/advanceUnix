#include"./../include/head.h"

int main(int argc,char* argv[])
{
	if( argc < 2)
		perror("Not enough command-line param!\n");

	int ret,status;
	pid_t endpid;
	pid_t another;

	ret = fork();
	
	printf("ret :%d\n",ret);
	//sleep(2);
	//printf("ret :%d\n",ret);//i think ret must be zero....but.......
	
	if(ret < 0){
		perror("fork failed!\n");
		goto err;
	}else if(ret == 0){
		printf("the first child,process %d!\n",getpid());
		ret = fork();
		if( ret < 0){
			printf("fork error in process %d\n",getpid());
		}if( ret > 0){
			printf("im process %d\n",getpid());
			exit(0);
		}
	}else{
	//	endpid = wait(&status);  //the parent process was suspend util one of her childs termitted.
		printf("last ret = %d\n",ret);
		endpid = waitpid(ret,&status,0);
		if(endpid != ret)
			perror("waitpid error!\n");
		printf("parent, process %d!\n",getpid());
	}
err:
	return 0;
}

