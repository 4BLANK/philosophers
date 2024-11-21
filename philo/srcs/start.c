/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasdouq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:34:57 by amasdouq          #+#    #+#             */
/*   Updated: 2024/08/01 13:34:59 by amasdouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	pick_forks(t_philosopher *p)
{
	if (one_tiny_philo(p))
		return (1);
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
	pthread_mutex_lock(&(params()->print_lock));
	printf("%lu philosopher %d picked a fork\n", fix_time(), p->id);
	pthread_mutex_unlock(&(params()->print_lock));
	return (0);
}

void	put_down_forks(t_philosopher *p)
{
	pthread_mutex_unlock(&(p->left->mtx));
	pthread_mutex_unlock(&(p->right->mtx));
}

int	eat(t_philosopher *p)
{
	if (pick_forks(p))
		return (1);
  print_e(p->id);
	pthread_mutex_lock(&(params()->mutex_last_meal));
	p->last_meal = fix_time();
	pthread_mutex_unlock(&(params()->mutex_last_meal));
	if (ft_usleep(1000 * (params()->time_to_eat), p->number_of_meals))
		return (1);
	pthread_mutex_lock(&(params()->print_lock));
	p->number_of_meals++;
	pthread_mutex_unlock(&(params()->print_lock));
	return (0);
}

int	p_sleep(t_philosopher *p)
{
	put_down_forks(p);
	if (check_death())
		return (1);
  print_s(p->id);
	if (ft_usleep(1000 * (params()->time_to_sleep), p->number_of_meals))
		return (1);
	if (check_death())
		return (1);
	return (0);
}

void	*start(void *p)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)p;
	if (philosopher->id % 2 == 0)
		ft_usleep(200, 0);
	while ((((params()->ac == 6)
				&& philosopher->number_of_meals != \
	params()->number_of_times_philosopher_must_eat))
		|| (params()->ac == 5))
	{
		if (eat(philosopher))
			break ;
		if (p_sleep(philosopher))
			break ;
		if (!check_death())
		{
      print_t(philosopher->id);
		}
		if (params()->number_of_philosophers % 2 != 0)
			usleep(1000);
		if (check_death())
			return (NULL);
	}
	return (NULL);
}
