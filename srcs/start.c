#include "../include/philosophers.h"
#include <pthread.h>

// to revisit
int pick_forks(philosopher_t *p)
{
  if (p->id % 2 != 0)
  {
    if (odd_philosopher(p))
      return (1);
  }
  else
{
    if (even_philospher(p))
      return (1);
  }
  printf("%lld philosopher %d picked a fork\n", fix_time(), p->id);
  pthread_mutex_unlock(&(params()->print_lock));
  return (0);
}

void put_down_forks(philosopher_t *p)
{
  pthread_mutex_unlock(&(p->left->mtx));
  pthread_mutex_unlock(&(p->right->mtx));
}

int eat(philosopher_t *p)
{
  death_check(p);
  if (pick_forks(p))
    return (1);
  pthread_mutex_lock(&(params()->print_lock));
  printf("%lld philosopher %d is eating\n", fix_time(), p->id);
  pthread_mutex_unlock(&(params()->print_lock));
  usleep(__to_milli__(params()->time_to_eat));
  p->last_meal = fix_time();
  pthread_mutex_lock(&(params()->print_lock));
  pthread_mutex_unlock(&(params()->print_lock));
  p->number_of_meals++;
  return (0);
}

int p_sleep(philosopher_t *p)
{
  put_down_forks(p);
  pthread_mutex_lock(&(params()->print_lock));
  if (params()->death)
  {
    pthread_mutex_unlock(&(params()->print_lock));
    return (1);
  }
  printf("%lld philosopher %d is sleeping\n", fix_time(), p->id);
  pthread_mutex_unlock(&(params()->print_lock));
  usleep(__to_milli__(params()->time_to_sleep));
  death_check(p);
  return (0);
}

void *start(void *p)
{
  philosopher_t *philosopher;

  philosopher = (philosopher_t *)p;
  if (philosopher->id % 2 == 0)
    usleep(200);
  while ((((params()->ac == 6) && philosopher->number_of_meals != params()->number_of_times_philosopher_must_eat))
  || (params()->ac == 5) && !(params()->death))
  {
    if (eat(philosopher))
      break ;
    if (p_sleep(philosopher))
      break ;
    if (!params()->death)
    {
      pthread_mutex_lock(&(params()->print_lock));
      printf("%lld philosopher %d is thinking\n", fix_time(), philosopher->id);
      pthread_mutex_unlock(&(params()->print_lock));
    }
    death_check(p);
  }
  return (NULL);
}
