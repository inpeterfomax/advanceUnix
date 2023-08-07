#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc,char*argv[])
{
	int msgid,msgid2;
	pid_t pid;
	key_t msg_key,msg_key2;
	char *str1 = "linux is my favoriate!";
	char *str2 = "i do like linux system!";
	int ret;

	struct msgbuf{
		long msgtype;
		char data[256];
	}sendmsg,recvmsg;
		
	msg_key = ftok("/tmp/msg",18);
	if(msg_key == -1)
		puts("parent ftok failed\n");

	msgid = msgget(msg_key,0666|IPC_CREAT);
	if(msgid == -1)
		puts("parent msgget failed\n");
	sendmsg.msgtype=100;
	sprintf(sendmsg.data,"%s",str1);
	if(msgsnd(msgid,&sendmsg,256,0) == -1)
		puts("parent msgsnd failed\n");
	
	if(( pid=fork()) < 0)
		puts("fork error\n");
	else if( pid == 0){
	/*	msg_key2 = ftok("/tmp/msg",18);
		if(msg_key2 == -1)
			puts("child ftok2 failed\n");

		msgid2 = msgget(msg_key2,0666);
		if(msgid == -1)
			puts("child msgget failed\n");
	*/
		ret = msgrcv(msgid,&recvmsg,256,100,0);
		printf("child reveive data:%s\n",recvmsg.data);
		memset(&recvmsg,0,sizeof(struct msgbuf));
		exit(-1);
	}else{
		waitpid(pid,NULL);
		msgctl(msgid,IPC_RMID,NULL);
	}
	return 0;
}
