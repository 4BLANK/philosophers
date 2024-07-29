#include "../include/philosophers.h"
#include <pthread.h>
#include <sys/time.h>

long long fix_time()
{
  struct timeval t;

  gettimeofday(&t, NULL);
  return ((t.tv_sec * 1000) + (t.tv_usec / 1000)) - params()->start_instant;
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

void death_check(philosopher_t *p)
{
  pthread_mutex_lock(&(params()->print_lock));
  if (!params()->death && fix_time() - p->last_meal >= (long long)params()->time_to_die)
  {
    printf("%lld philosopher %d is dead :(\n", fix_time(), p->id);
    params()->death = 1;
  }
  pthread_mutex_unlock(&(params()->print_lock));
}
