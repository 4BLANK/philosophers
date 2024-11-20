/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasdouq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:35:25 by amasdouq          #+#    #+#             */
/*   Updated: 2024/08/01 13:35:27 by amasdouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct fork_s
{
	pthread_mutex_t	mtx;
	int				id;
}					t_fork;

typedef struct philospher_s
{
	pthread_t		thread;
	t_fork			*left;
	t_fork			*right;
	int				number_of_meals;
	long long		last_meal;
	int				id;
}					t_philosopher;

typedef struct params_s
{
	unsigned long	number_of_philosophers;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	number_of_times_philosopher_must_eat;
	int				death;
	unsigned long	start_instant;
	int				ac;
	pthread_mutex_t	death_note;
	pthread_mutex_t	print_lock;
	t_philosopher	**list_p;
	t_fork			**list_f;
}					t_params;

void				create_forks(void);
void				create_philosophers(void);
void				*start(void *p);
void				join_philosophers(void);
unsigned long		fix_time(void);
void				death_check(t_philosopher *p);
int					even_philospher(t_philosopher *p);
int					odd_philosopher(t_philosopher *p);
void				clean_philosophers(void);
void				clean_forks(void);
int					one_tiny_philo(t_philosopher *p);
int					clean(void);
int					error_handling(int ac, char **av);
t_params			*params(void);
void				ryuku(void);

void				odd_philosopher_first_con(t_philosopher *p);
void				odd_philosopher_non_con(t_philosopher *p);
void				odd_philosopher_second_con(t_philosopher *p);
void				even_philosopher_first_con(t_philosopher *p);
void				even_philosopher_non_con(t_philosopher *p);
void				even_philosopher_second_con(t_philosopher *p);
int    ft_usleep(long time_to_sleep, int meals_eaten);
int	error_handling2();
