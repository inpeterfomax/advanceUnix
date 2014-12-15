
#include <assert.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


// Counting semaphore.

struct csema
{
  pthread_mutex_t  m_mutex;
  pthread_cond_t   m_cond;
  int              m_count;
};

void csema_ctr(struct csema* p)
{
  memset(p, 0, sizeof(*p));
  pthread_mutex_init(&p->m_mutex, 0);
  pthread_cond_init(&p->m_cond, 0);
}

void csema_dtr(struct csema* p)
{
  pthread_cond_destroy(&p->m_cond);
  pthread_mutex_destroy(&p->m_mutex);
}

void csema_p(struct csema* p, const int n)
{
  pthread_mutex_lock(&p->m_mutex);
  printf("[0x%x],csema_p(),%d\n",pthread_self(),(p->m_count < n));		
  while (p->m_count < n)
    pthread_cond_wait(&p->m_cond, &p->m_mutex);
  p->m_count -= n;
  pthread_cond_signal(&p->m_cond);
  pthread_mutex_unlock(&p->m_mutex);
}

void csema_v(struct csema* p)
{
  printf("[0x%x],csema_v()\n",pthread_self());		
  pthread_mutex_lock(&p->m_mutex);
  p->m_count++;
  pthread_cond_signal(&p->m_cond);
  pthread_mutex_unlock(&p->m_mutex);
}


struct cthread
{
  pthread_t     m_thread;
  int           m_threadnum;
  struct csema* m_sema;
};

void cthread_ctr(struct cthread* p)
{
  p->m_thread = 0;
  p->m_sema   = 0;
}

void cthread_dtr(struct cthread* p)
{ }


// Local variables.

static int s_debug = 1;
static int s_trace = 1;
static int s_signal_count;
static pthread_mutex_t s_mutex;
static pthread_cond_t  s_cond;


// Function definitions.

static void thread_func(struct cthread* thread_info)
{
  int i;
  printf("[0x%x]1thread \n",pthread_self());
  pthread_mutex_lock(&s_mutex);
  
  for (i = 0; i < s_signal_count; i++)
  {
    csema_v(thread_info->m_sema);
    if (s_trace)
    {
      printf("[0x%x]2thread %d [%d] (1)\n",pthread_self(), thread_info->m_threadnum, i);
    }

    // Wait until the main thread signals us via pthread_cond_broadcast().
    pthread_cond_wait(&s_cond, &s_mutex);
    if (s_trace)
    {
      printf("[0x%x]3thread %d [%d] (2)\n",pthread_self(), thread_info->m_threadnum, i);
    }
  }

  pthread_mutex_unlock(&s_mutex);
}

int main(int argc, char** argv)
{
  int optchar;
  int thread_count;


  /* This test should complete in 15s or less. If the test does not complete */
  /* within that time, abort the test via the signal SIGALRM.                */
  //alarm(100);

  s_signal_count =  1;
  thread_count =  1;

  if (s_debug)
    printf("&s_cond = %p\n", &s_cond);

  pthread_mutex_init(&s_mutex, 0);
  pthread_cond_init(&s_cond, 0);
  {
    int i;
    struct csema sema;
    struct cthread* p;
    struct cthread* thread_vec;

    csema_ctr(&sema);
    thread_vec = malloc(sizeof(struct cthread) * thread_count);
    for (p = thread_vec; p != thread_vec + thread_count; p++)
    {
      cthread_ctr(p);
      p->m_threadnum = p - thread_vec;
      p->m_sema = &sema;
      pthread_create(&p->m_thread, 0,
                     (void*(*)(void*))thread_func, &*p);
    }

	printf("There are 2 threads exist \n");
    for (i = 0; i < s_signal_count; i++)
    {
      if (s_trace)
        printf("[0x%x]main [%d] m_count=%d (1)\n",pthread_self(), i,sema.m_count);
      csema_p(&sema, thread_count);

      if (s_trace)
        printf("[0x%x]main [%d] (2)\n",pthread_self(), i);
      
	  pthread_mutex_lock(&s_mutex);
      pthread_cond_broadcast(&s_cond);
      pthread_mutex_unlock(&s_mutex);
      
	  if (s_trace)
        printf("[0x%x]main [%d] (3)\n",pthread_self(), i);
    }
	
    for (i = 0; i < thread_count; i++)
    {
      pthread_join(thread_vec[i].m_thread, 0);
      cthread_dtr(&thread_vec[i]);
    }
    free(thread_vec);
    csema_dtr(&sema);
  }
  pthread_cond_destroy(&s_cond);
  pthread_mutex_destroy(&s_mutex);

  fprintf(stderr, "Done.\n");

  return 0;
}
