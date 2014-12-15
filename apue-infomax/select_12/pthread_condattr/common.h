#ifndef __COMMON_H
#define __COMMON_H
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdio.h>

#define SHARE_PATH "/sharemorery"
#define SHARE_FLAG (O_RDWR| O_CREAT)
#define SHARE_MODE (0660)
#define SHARE_LEN (1024)

struct share_struct{
   pthread_cond_t cond;
   pthread_mutex_t mutex;
   int data;
};

#endif
