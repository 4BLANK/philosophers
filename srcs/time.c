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
