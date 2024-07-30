#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

#define __to_milli__(__m__) __m__*1000

typedef struct fork_s
{
  pthread_mutex_t mtx;
  int id;
} fork_t;

typedef struct philospher_s
{
  pthread_t thread;
  fork_t *left;
  fork_t *right;
  int number_of_meals;
  long long last_meal;
  int id;
} philosopher_t;

typedef struct params_s 
{
  int number_of_philosophers;
  int time_to_die;
  int time_to_eat;
  int time_to_sleep;
  int number_of_times_philosopher_must_eat;
  int death;
  long long start_instant;
  int ac;
  pthread_mutex_t print_lock;
  pthread_mutex_t lock;
  philosopher_t **list_p;
  fork_t **list_f;
} params_t;

void create_forks();
void create_philosophers();
void *start(void *p);
void join_philosophers();
long long fix_time();
void death_check(philosopher_t *p);
int even_philospher(philosopher_t *p);
int odd_philosopher(philosopher_t *p);
void clean_philosophers();
void clean_forks();
int clean();
params_t *params();
