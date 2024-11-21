/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasdouq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:34:31 by amasdouq          #+#    #+#             */
/*   Updated: 2024/08/01 13:34:33 by amasdouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	check_death(void)
{
	int	stop;

	pthread_mutex_lock(&(params()->death_note));
	stop = params()->death;
	pthread_mutex_unlock(&(params()->death_note));
	return (stop);
}

void print_t(int id)
{
  pthread_mutex_lock(&(params()->print_lock));
  printf("%lu philosopher %d is thinking\n", fix_time(),
         id);
  pthread_mutex_unlock(&(params()->print_lock));
}

void print_s(int id)
{
	pthread_mutex_lock(&(params()->print_lock));
	printf("%lu philosopher %d is sleeping\n", fix_time(), id);
	pthread_mutex_unlock(&(params()->print_lock));
}

void print_e(int id)
{
	pthread_mutex_lock(&(params()->print_lock));
	printf("%lu philosopher %d is eating\n", fix_time(), id);
	pthread_mutex_unlock(&(params()->print_lock));
}
