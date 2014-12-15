#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <string.h>

#include "apis.h"

#define NLOOPS       16 
#define SIZE         sizeof(long)     /* size of shared memory area */

static int update(long *ptr)
{
    return((*ptr)++);    			/* return value before increment */
}

int main(void)
{
    int     fd, i, counter;
    pid_t   pid;
    void    *area;

    if ((fd = open("/dev/zero", O_RDWR)) < 0)
        printf("open error:%d %s\n",errno,strerror(errno));

    if ((area = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED,fd, 0)) == MAP_FAILED)
        printf("mmap error:%d %s\n",errno,strerror(errno));

    close(fd);      				/* can close /dev/zero now that it's mapped */

    TELL_WAIT();

    if ((pid = fork()) < 0) {
        printf("fork error");
    } else if (pid > 0) {           /* parent */
        for (i = 0; i < NLOOPS; i += 2) {
            if ((counter = update((long *)area)) != i)
                printf("parent: expected %d, got %d", i, counter);
			printf("parent:%d counter :%d \n",getpid(),counter);
            
			TELL_CHILD(pid);
            WAIT_CHILD();
        }
    } else {                         /* child */
        for (i = 1; i < NLOOPS + 1; i += 2) {
            WAIT_PARENT();

            if ((counter = update((long *)area)) != i)
                printf("child: expected %d, got %d", i, counter);
			printf("child:%d counter :%d \n",getpid(),counter);
            
			TELL_PARENT(getppid());
        }
    }

    exit(0);
}

