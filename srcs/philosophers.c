#include "../include/philosophers.h"

void init_params(int ac, char **av)
{
  pthread_mutex_init(&(params()->print_lock), NULL);
  pthread_mutex_init(&(params()->lock), NULL);
  pthread_mutex_lock(&(params()->print_lock));
  params()->number_of_philosophers = atoi(av[1]);
  params()->time_to_die = atoi(av[2]);
  params()->time_to_eat = atoi(av[3]);
  params()->time_to_sleep = atoi(av[4]);
  params()->number_of_times_philosopher_must_eat = 0;
  params()->ac = ac;
  params()->death = 0;
  if (ac == 6)
    params()->number_of_times_philosopher_must_eat = atoi(av[5]);
  params()->start_instant = 0;
  params()->start_instant = fix_time();
  pthread_mutex_unlock(&(params()->print_lock));
  create_forks();
  create_philosophers();
  join_philosophers();
}

int main(int ac, char **av)
{
  if(ac == 5 || ac == 6)
  {
    init_params(ac, av);
    clean();
  }
  return (0);
}
