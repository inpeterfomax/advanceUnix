#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

typedef void Sigfunc(int);
Sigfunc * signal_intr(int signo,Sigfunc *func){
    struct sigaction act ,oact;
    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
#ifdef SA_INTERRUPT
    act.sa_flags |= SA_INTERRUPT;
#endif
    if (sigaction(signo,&act,&oact)<0)
        return (SIG_ERR);
    return (oact.sa_handler);
}

static void sig_usr1(int);

int main(void){
   if(signal_intr(SIGUSR1,sig_usr1) == SIG_ERR)
       printf("SIGUSR1 error \n");
   kill(getpid(),SIGUSR1);
   sleep(5);
}

static void sig_usr1(int signo){
    printf("SIGUSR1 happen\n");
}
