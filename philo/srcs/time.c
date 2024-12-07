/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasdouq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:35:03 by amasdouq          #+#    #+#             */
/*   Updated: 2024/11/27 15:04:49 by amasdouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_usleep(unsigned long time_to_sleep, unsigned long meals_eaten)
{
	unsigned long	start_time;

	start_time = fix_time() * 1000;
	while (fix_time() * 1000 - start_time < time_to_sleep)
	{
		if (params()->ac == 6
			&& meals_eaten == params()->number_of_times_philosopher_must_eat)
			return (1);
		if (check_death())
			break ;
		usleep(100);
		if (params()->ac == 6
			&& meals_eaten == params()->number_of_times_philosopher_must_eat)
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
