
#include <errno.h>
#if !defined(_AIX) && !defined(__APPLE__)
# include <error.h>
#endif
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

#if defined(_AIX) || defined(__APPLE__)
#include <string.h>  /* strerror */
static void error (int status, int errnum, char* msg)
{
   fprintf(stderr, "%s%s%s\n",
           msg,
           errnum ? ": " : "",
           errnum ? strerror(errnum) : "");
   if (errnum)
      exit(errnum);
}
#endif

enum
{
  PREPARE_BIT = 1,
  PARENT_BIT = 2,
  CHILD_BIT = 4
};

static int var;

static void
prepare (void)
{
		printf("prepare() \n");
  var |= PREPARE_BIT;
}

static void
parent (void)
{
		printf("parent() \n");
  var |= PARENT_BIT;
}

static void
child (void)
{
		printf("child() \n");
  var |= CHILD_BIT;
}


static void *thread (void *arg);


int
main (void)
{
  pthread_t th;
  void *res;

  pthread_atfork (prepare, parent, child);

  if (pthread_create (&th, NULL, thread, NULL) != 0)
    error (EXIT_FAILURE, 0, "cannot create thread");

  pthread_join (th, &res);

  if ( ( int ) ( long int ) res != 0 )
      error(EXIT_FAILURE, 0, "pthread_join res != 0" );
  printf ( "all ok\n");
  return 0;
}


static void *
thread (void *arg)
{
  int status;
  pid_t pid;
  printf("111111111111111111\n");
  pid = fork ();
  if (pid == 0)
    {
			printf("22222222222222222\n");
			/* We check whether the `prepare' and `child' function ran.  */
      exit (var != (PREPARE_BIT | CHILD_BIT));
    }
  else if (pid == (pid_t) -1)
    error (EXIT_FAILURE, errno, "cannot fork");

  if (waitpid (pid, &status, 0) != pid)
    error (EXIT_FAILURE, errno, "wrong child");

  if (WTERMSIG (status) != 0)
    error (EXIT_FAILURE, 0, "Child terminated incorrectly");
  status = WEXITSTATUS (status);
  printf("thread() status=%d,var=%d\n",status,var);
  if (status == 0)
    status = var != (PREPARE_BIT | PARENT_BIT);

  return (void *) (long int) status;
}
