#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static void sig_alrm(int signo){
    /*nothing to do ,just returning wakes up sigsuspend()*/
}

unsigned int sleep1(unsigned int nsecs){
    struct sigaction newact,oldact;
    sigset_t newmask,oldmask,suspmask;
    unsigned int unslept;
    /*set our handler, save previous information*/
    newact.sa_handler = sig_alrm;
    sigemptyset(&newact.sa_mask);
    newact.sa_flags = 0;
    sigaction(SIGALRM,&newact,&oldact);
    /*block SIGGLRM and save current signal mask*/
    sigemptyset(&newmask);
    sigaddset(&newmask,SIGALRM);
    sigprocmask(SIG_BLOCK,&newmask,&oldmask);
    alarm(nsecs);
    suspmask = oldmask;
    sigdelset(&suspmask,SIGALRM);/*make sure SIGALRM isn't blocked*/
    sigsuspend(&suspmask); /*wait for any signal to be caught*/
    /*some signal has been caught ,SIGALRM is now blocked*/
    unslept = alarm(0);
    sigaction(SIGALRM,&oldact,NULL);/*reset previous action*/
    /*reset signal mask ,which unblocks SIGALRM*/
    sigprocmask(SIG_SETMASK,&oldmask,NULL);
    return (unslept);
}

int main(void){
    printf("before sleep1 5 second\n");
    sleep1(5);
    printf("after sleep1 5 second\n");
}
