/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ryuku.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasdouq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:34:52 by amasdouq          #+#    #+#             */
/*   Updated: 2024/08/01 13:34:54 by amasdouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"
#include <pthread.h>

void *job(void *p)
{
	int i;

	i = 0;
	(void)p;
	while (!check_death())
	{
		pthread_mutex_lock(&(params()->mutex_last_meal));
		if (!check_death() && fix_time() - params()->list_p[i]->last_meal > params()->time_to_die)
		{
			if ((((params()->ac == 6) && params()->list_p[i]->number_of_meals == params()->number_of_times_philosopher_must_eat)))
				return (pthread_mutex_unlock(&(params()->mutex_last_meal)), NULL);
			pthread_mutex_lock(&(params()->death_note));
			params()->death = i + 1;
			pthread_mutex_unlock(&(params()->death_note));
			return (pthread_mutex_unlock(&(params()->mutex_last_meal)), NULL);
		}
		pthread_mutex_unlock(&(params()->mutex_last_meal));
		if (!params()->list_p[++i])
			i = 0;
	}
	return (NULL);
}

void ryuku(void)
{
	pthread_t thread;

	if (pthread_create(&thread, NULL, job, NULL))
		return;
	if (pthread_join(thread, NULL))
		return;
}
