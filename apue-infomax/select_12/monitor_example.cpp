#define _GNU_SOURCE 1
#include <cassert>
#include <iostream>
#include <pthread.h>
#include<stdio.h>

class Monitor
{
public:
  Monitor()
    : m_mutex()
    , m_cond()
    , m_owner()
    , m_recursion_count()
  {
    pthread_mutexattr_t mutexattr;
    pthread_mutexattr_init(&mutexattr);
    pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&m_mutex, &mutexattr);
    pthread_mutexattr_destroy(&mutexattr);
    pthread_condattr_t condattr;
    pthread_condattr_init(&condattr);
#if defined(HAVE_PTHREAD_CONDATTR_SETCLOCK)
    pthread_condattr_setclock(&condattr, CLOCK_MONOTONIC);
#endif
    pthread_cond_init(&m_cond, &condattr);
    pthread_condattr_destroy(&condattr);
  }
  ~Monitor()
  {
	printf("~Monitor()\n");	  
    assert(m_recursion_count == 0);
    pthread_cond_destroy(&m_cond);
    pthread_mutex_destroy(&m_mutex);
  }
  void lock()
  {
    pthread_mutex_lock(&m_mutex);
    assert(m_recursion_count >= 0);
    if (++m_recursion_count == 1)
    {
      m_owner = pthread_self();
    }
  }
  void unlock()
  {
    m_recursion_count--;
    assert(m_recursion_count >= 0);
    pthread_mutex_unlock(&m_mutex);
  }
  void wait()
  {
    assert(m_recursion_count == 1);
    assert(m_owner == pthread_self());
    m_recursion_count--;
    pthread_cond_wait(&m_cond, &m_mutex);
    m_recursion_count++;
    m_owner = pthread_self();
  }
  void signal()
  {
    assert(m_recursion_count > 0);
    pthread_cond_signal(&m_cond);
  }
  void broadcast_signal()
  {
    assert(m_recursion_count > 0);
    pthread_cond_broadcast(&m_cond);
  }
  bool is_locked_by_self()
  {
    bool result;
    pthread_mutex_lock(&m_mutex);
    result = m_recursion_count > 0 && m_owner == pthread_self();
    pthread_mutex_unlock(&m_mutex);
    return result;
  }

private:
  Monitor(const Monitor&);
  Monitor& operator=(const Monitor&);

  pthread_mutex_t m_mutex;
  pthread_cond_t  m_cond;
  pthread_t       m_owner;
  int             m_recursion_count;
};


class ScopedLock
{
public:
  ScopedLock(Monitor& m)
    : m_monitor(m)
    , m_locked(false)
  { lock(); }
  ~ScopedLock()
  { printf("~ScopedLock()\n"); if (m_locked) unlock(); }
  void lock()
  { assert(! m_locked); m_monitor.lock(); m_locked = true; }
  void unlock()
  { assert(m_locked); m_locked = false; m_monitor.unlock(); }

private:
  ScopedLock(const ScopedLock&);
  ScopedLock& operator=(const ScopedLock&);

  Monitor& m_monitor;
  bool     m_locked;
};


class StateVariable
{
public:
  StateVariable()
    : m_state()
  { }
  int get()
  {
    ScopedLock sl(m_monitor);
    return m_state;
  }
  void set(const int state)
  {
    printf("StateVariable::set() \n");		  
    ScopedLock sl(m_monitor);
    m_state = state;
    m_monitor.signal();
  }
  void wait(const int state)
  {
	printf("StateVariable::wait()\n");	  
    ScopedLock sl(m_monitor);
    while (m_state != state)
      m_monitor.wait();
  }

private:
  Monitor m_monitor;
  int     m_state;
};


static StateVariable s_sv;


static void* thread_func(void*)
{
  sleep(2);		
  printf("thread_func()  wait(1) \n");		
  s_sv.wait(1);
  printf("thread_func() set(2) \n");
  s_sv.set(2);
  printf("thread_func() wait(3) \n");
  s_sv.wait(3);
  printf("thread_func() set(4)\n");
  s_sv.set(4);
  return 0;
}

int main(int, char**)
{
  pthread_t tid;
  pthread_create(&tid, 0, thread_func, 0);
  printf("main() set(1) \n");
  s_sv.set(1);
  printf("main() wait(2) \n");
  s_sv.wait(2);
  printf("main() set(3)\n");
  s_sv.set(3);
  printf("main()  wait(4)\n");
  s_sv.wait(4);
  pthread_join(tid, 0);
  std::cerr << "Finished successfully.\n";
  return 0;
}
