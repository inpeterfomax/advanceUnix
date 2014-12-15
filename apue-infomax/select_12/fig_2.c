#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

struct to_info {
    void (*to_fn)(void *);   /* function */
    void * to_arg;           /* argument */ 
    struct timespec to_wait; /* time to wait */
};

int 
makethread(void * (*fn)(void *), void * arg, int detach)
{
    int             err;
    int             detachstate;
    pthread_t       tid;
    pthread_attr_t  attr;

    if ((err = pthread_attr_init(&attr)) != 0) {
        return(err);
    }
    if (detach != 0) {
        detachstate = PTHREAD_CREATE_DETACHED;
    }
    else {
        detachstate = PTHREAD_CREATE_JOINABLE;
    }
    err = pthread_attr_setdetachstate(&attr, detachstate);
    if (err == 0) {
        err = pthread_create(&tid, &attr, fn, arg);
    }
    pthread_attr_destroy(&attr);
    return(err);
}

void * 
timeout_helper(void * arg)
{
    struct to_info * tip;

    tip = (struct to_info *)arg;
    nanosleep(&tip->to_wait, NULL);
    (*tip->to_fn)(tip->to_arg);
    free(arg);
    return((void *)0);
}

void 
timeout(const struct timespec * when, void (*func)(void *), void * arg)
{
    struct timespec  now;
    struct timeval   tv;
    struct to_info * tip;
    int              err;

    gettimeofday(&tv, NULL);
    now.tv_sec = tv.tv_sec;
    now.tv_nsec = tv.tv_usec * 1000;
    if ((when->tv_sec > now.tv_sec) || 
        (when->tv_sec == now.tv_sec && when->tv_nsec > now.tv_nsec)) {
        tip = (struct to_info *)malloc(sizeof(struct to_info));
        if (tip != NULL) {
            tip->to_fn = func;
            tip->to_arg = arg;
            tip->to_wait.tv_sec = when->tv_sec - now.tv_sec;
            if (when->tv_nsec >= now.tv_nsec) {
                tip->to_wait.tv_nsec = when->tv_nsec - now.tv_nsec;
            }
            else {
                --tip->to_wait.tv_sec;
                tip->to_wait.tv_nsec = 1000000000 - now.tv_nsec + when->tv_nsec;
            }

            err = makethread(timeout_helper, tip, 1);
            if (err == 0) {
                return;
            }
            else {
                free(tip);
            }
        }
    }

    (*func)(arg);
}

pthread_mutexattr_t attr;
pthread_mutex_t mutex;

void 
retry(void * arg)
{
    pthread_mutex_lock(&mutex);
    /* ... perform retry steps ... */
    printf("it is a test\n");
    pthread_mutex_unlock(&mutex);
}

void 
maketimespec(struct timespec * tsp, long seconds)
{
    struct timeval now;

    gettimeofday(&now, NULL);
    tsp->tv_sec = now.tv_sec;
    tsp->tv_nsec = now.tv_usec * 1000;
    tsp->tv_sec += seconds;
}

int 
main(void)
{
    int             err;
    int             condition;
    int             arg;
    struct timespec when;

    if ((err = pthread_mutexattr_init(&attr)) != 0) {
        printf("pthread_mutexattr_init failed\n");
        return(1);
    }
    err = pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    if (err != 0) {
        printf("pthread_mutexattr_settype failed\n");
    }
    else if ((err = pthread_mutex_init(&mutex, &attr)) != 0) {
        printf("pthread_mutex_init failed\n");
    }
    pthread_mutexattr_destroy(&attr);
    if (err != 0) {
        return(1);
    }
    /* ... */
    pthread_mutex_lock(&mutex);
    condition = 1;
    if (condition) {
        /* calculate target time "when" */
        maketimespec(&when, 5);
        timeout(&when, retry, (void *)arg);
    }
    /* ... */
    pthread_mutex_unlock(&mutex);
    /* ... */
    sleep(10); /* wait */
    exit(0); /* fflush */
}