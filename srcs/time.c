/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasdouq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:35:03 by amasdouq          #+#    #+#             */
/*   Updated: 2024/08/01 13:35:04 by amasdouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int    ft_usleep(long time_to_sleep, int meals_eaten)
{
  long    start_time;

  start_time = fix_time() * 1000;
  while (fix_time() * 1000 - start_time < time_to_sleep)
  {
    if (params()->ac == 6 && meals_eaten == params()->number_of_times_philosopher_must_eat)
      return (1);
    if (params()->death)
      break;
    usleep(100);
    if (params()->ac == 6 && meals_eaten == params()->number_of_times_philosopher_must_eat)
      return (1);
  }
  return (0);
}

unsigned long	fix_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((unsigned long)((unsigned long)(t.tv_sec * 1000)
			+ (unsigned long)(t.tv_usec / 1000)) - params()->start_instant);
}

void	unlock_all_forks(void)
{
	int	i;

	i = 0;
	while (params()->list_f[i])
	{
		pthread_mutex_unlock(&(params()->list_f[i]->mtx));
		i++;
	}
}
