#include "../include/philosophers.h"

int odd_philosopher(philosopher_t *p)
{
  pthread_mutex_lock(&(p->left->mtx));
  pthread_mutex_lock(&(params()->print_lock));
  if (params()->death)
  {
    pthread_mutex_unlock(&(params()->print_lock));
    pthread_mutex_unlock(&(p->left->mtx));
    return (1);
  }
  printf("%lld philosopher %d picked a fork\n", fix_time(), p->id);
  pthread_mutex_unlock(&(params()->print_lock));
  death_check(p);
  pthread_mutex_lock(&(p->right->mtx));
  pthread_mutex_lock(&(params()->print_lock));
  if (params()->death)
  {
    pthread_mutex_unlock(&(p->left->mtx));
    pthread_mutex_unlock(&(params()->print_lock));
    pthread_mutex_unlock(&(p->right->mtx));
    return (1);
  }
  return (0);
}

int even_philospher(philosopher_t *p)
{
  pthread_mutex_lock(&(p->right->mtx));
  pthread_mutex_lock(&(params()->print_lock));
  if (params()->death)
  {
    pthread_mutex_unlock(&(p->right->mtx));
    pthread_mutex_unlock(&(params()->print_lock));
    return (1);
  }
  printf("%lld philosopher %d picked a fork\n", fix_time(), p->id);
  pthread_mutex_unlock(&(params()->print_lock));
  death_check(p);
  pthread_mutex_lock(&(p->left->mtx));
  pthread_mutex_lock(&(params()->print_lock));
  if (params()->death)
  {
    pthread_mutex_unlock(&(p->right->mtx));
    pthread_mutex_unlock(&(params()->print_lock));
    pthread_mutex_unlock(&(p->left->mtx));
    return (1);
  }
  return (0);
}
