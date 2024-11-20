/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasdouq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:34:46 by amasdouq          #+#    #+#             */
/*   Updated: 2024/08/01 13:34:49 by amasdouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	init_params(int ac, char **av)
{
	pthread_mutex_init(&(params()->print_lock), NULL);
	pthread_mutex_init(&(params()->death_note), NULL);
	pthread_mutex_lock(&(params()->print_lock));
	params()->number_of_philosophers = (unsigned long)atol(av[1]);
	params()->time_to_die = (unsigned long)atol(av[2]);
	params()->time_to_eat = (unsigned long)atol(av[3]);
	params()->time_to_sleep = (unsigned long)atol(av[4]);
	params()->number_of_times_philosopher_must_eat = 0;
	params()->ac = ac;
	params()->death = 0;
	if (ac == 6)
		params()->number_of_times_philosopher_must_eat = (unsigned long) \
				atoi(av[5]);
	params()->start_instant = 0;
	params()->start_instant = fix_time();
	pthread_mutex_unlock(&(params()->print_lock));
  if (error_handling2())
    return ;
	create_forks();
	create_philosophers();
	ryuku();
	join_philosophers();
}

int	main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		if (error_handling(ac, av))
		{
			printf("Error\n");
			return (1);
		}
		init_params(ac, av);
    if (params()->death)
      printf("%lu philosopher %d is dead :p\n", fix_time(), params()->death);
		clean();
	}
	return (0);
}
