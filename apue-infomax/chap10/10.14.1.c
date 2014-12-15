#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
/**
 * demo signal same func.
 * **/

typedef void Sigfunc(int);
Sigfunc * signal1(int signo,Sigfunc *func){
    struct sigaction act ,oact;
    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    if (signo == SIGALRM){
#ifdef SA_INTERRUPT
        act.sa_flags |= SA_INTERRUPT;
#endif
    } else {

#ifdef SA_RESTART
        act.sa_flags |= SA_RESTART;
#endif
    }
    if (sigaction(signo,&act,&oact)<0)
        return (SIG_ERR);
    return (oact.sa_handler);
}

static void sig_usr1(int);

int main(void){
   if(signal1(SIGUSR1,sig_usr1) == SIG_ERR)
       printf("SIGUSR1 error \n");
   kill(getpid(),SIGUSR1);
   sleep(5);
}

static void sig_usr1(int signo){
    printf("SIGUSR1 happen\n");
}
