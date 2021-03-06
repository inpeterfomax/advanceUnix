#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static volatile sig_atomic_t sigflag;/*set nonzero by sig handler*/
static sigset_t newmask,oldmask,zeromask;

static void sig_usr(int signo){
    sigflag = 1;
    printf("set sigflag =1 \n");
}

void TELL_WAIT(void){
    if ( signal(SIGUSR1,sig_usr) == SIG_ERR )
        printf("signal (SIGUSR1) error\n");
    if (signal(SIGUSR2,sig_usr) == SIG_ERR )
        printf("signal (SIGUSR2) error \n");
    sigemptyset(&zeromask);
    sigaddset(&newmask,SIGUSR1);
    sigaddset(&newmask,SIGUSR2);
    /**
     * Block SIGUSR1 and SIGUSR2,and save current signal  mask.
     * **/
    if ( sigprocmask(SIG_BLOCK,&newmask,&oldmask) <0 )
        printf("SIG_BLOCK error\n");
}

void  TELL_PARENT(pid_t pid){
    kill(pid,SIGUSR2);
}

void WAIT_PARENT(void){
    while(sigflag == 0)
        sigsuspend(&zeromask);/*and wait for parent*/
    sigflag = 0;
    /**
     * Reset  signal mask to original value.
     * **/
    if ( sigprocmask(SIG_SETMASK, &oldmask,NULL) < 0 )
        printf("SIG_SETMASK error \n");
}

void TELL_CHILD(pid_t pid){
    kill(pid,SIGUSR1);
}

void WAIT_CHILD(void){
    while(sigflag == 0)
        sigsuspend(&zeromask); /*and wait for child*/
    sigflag = 0;
    /**
     * Reset signal mask to original value.
     * **/
    if ( sigprocmask(SIG_SETMASK,&oldmask,NULL) < 0 )
        printf("SIG_SETMASK error \n");
}
