/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasdouq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:35:25 by amasdouq          #+#    #+#             */
/*   Updated: 2024/11/27 15:02:02 by amasdouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

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
	unsigned long	number_of_meals;
	unsigned long	last_meal;
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
	pthread_mutex_t	mutex_last_meal;
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

int					ft_usleep(unsigned long time_to_sleep,
						unsigned long meals_eaten);
int					error_handling2(void);
int					check_death(void);
void				print_t(int id);
void				print_s(int id);
void				print_e(int id);
int					ft_strlen(char *str);
#endif
