#include "../include/philosophers.h"
#include <pthread.h>
#include <sys/time.h>

unsigned long fix_time()
{
  struct timeval t;

  gettimeofday(&t, NULL);
  return (unsigned long)((unsigned long)(t.tv_sec * 1000) + (unsigned long)(t.tv_usec / 1000)) - params()->start_instant;
}

void unlock_all_forks()
{
  int i;

  i = 0;
  while (params()->list_f[i])
  {
    pthread_mutex_unlock(&(params()->list_f[i]->mtx));
    i++;
  }
}
