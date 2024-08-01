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

void	*job(void *p)
{
	int	i;

	i = 0;
	(void)p;
	while (!params()->death)
	{
		if (!params()->death && fix_time()
			- params()->list_p[i]->last_meal >= params()->time_to_die)
		{
			pthread_mutex_lock(&(params()->death_note));
			params()->death = 1;
			pthread_mutex_unlock(&(params()->death_note));
			pthread_mutex_lock(&(params()->print_lock));
			printf("%lu philosopher %d is dead :p\n", fix_time(),
				params()->list_p[i]->id);
			pthread_mutex_unlock(&(params()->print_lock));
			return (NULL);
		}
		if (!params()->list_p[++i])
			i = 0;
	}
	return (NULL);
}

void	ryuku(void)
{
	pthread_t	thread;

	if (pthread_create(&thread, NULL, job, NULL))
		return ;
	if (pthread_join(thread, NULL))
		return ;
}
