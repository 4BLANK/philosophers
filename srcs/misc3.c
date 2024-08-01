/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasdouq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:34:37 by amasdouq          #+#    #+#             */
/*   Updated: 2024/08/01 13:34:38 by amasdouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	even_philosopher_first_con(t_philosopher *p)
{
	pthread_mutex_unlock(&(params()->death_note));
	pthread_mutex_unlock(&(p->right->mtx));
	pthread_mutex_unlock(&(params()->print_lock));
}

void	even_philosopher_non_con(t_philosopher *p)
{
	pthread_mutex_unlock(&(params()->death_note));
	pthread_mutex_lock(&(p->left->mtx));
	pthread_mutex_lock(&(params()->print_lock));
	pthread_mutex_lock(&(params()->death_note));
}

void	even_philosopher_second_con(t_philosopher *p)
{
	pthread_mutex_unlock(&(params()->death_note));
	pthread_mutex_unlock(&(p->right->mtx));
	pthread_mutex_unlock(&(params()->print_lock));
	pthread_mutex_unlock(&(p->left->mtx));
}
