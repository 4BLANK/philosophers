#include "../include/philosophers.h"

int	one_tiny_philo(t_philosopher *p)
{
	if (params()->number_of_philosophers == 1)
	{
		pthread_mutex_lock(&(p->left->mtx));
		pthread_mutex_lock(&(params()->print_lock));
		printf("%lu philosopher %d picked a fork\n", fix_time(), p->id);
		pthread_mutex_unlock(&(params()->print_lock));
		pthread_mutex_unlock(&(p->left->mtx));
		return (1);
	}
	return (0);
}

long	ft_atol(const char *str)
{
	long int	nb;
	int			sign;

	nb = 0;
	sign = 1;
	while ((*str) == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = (-1);
		str++;
	}
	while ((*str) >= '0' && (*str) <= '9')
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (sign * nb);
}

int	ft_strlen(char *str)
{
	if (!(*str))
		return (0);
	return (ft_strlen(str++) + 1);
}

int	odd_philosopher(t_philosopher *p)
{
	pthread_mutex_lock(&(p->left->mtx));
	pthread_mutex_lock(&(params()->print_lock));
	pthread_mutex_lock(&(params()->death_note));
	if (params()->death)
	{
		odd_philosopher_first_con(p);
		return (1);
	}
	pthread_mutex_unlock(&(params()->death_note));
	printf("%lu philosopher %d picked a fork\n", fix_time(), p->id);
	pthread_mutex_unlock(&(params()->print_lock));
	pthread_mutex_lock(&(params()->death_note));
	if (params()->death)
	{
		pthread_mutex_unlock(&(params()->death_note));
		pthread_mutex_unlock(&(p->left->mtx));
		return (1);
	}
	odd_philosopher_non_con(p);
	if (params()->death)
	{
		odd_philosopher_second_con(p);
		return (1);
	}
	return (pthread_mutex_unlock(&(params()->death_note)));
}

int	even_philospher(t_philosopher *p)
{
	pthread_mutex_lock(&(p->right->mtx));
	pthread_mutex_lock(&(params()->print_lock));
	pthread_mutex_lock(&(params()->death_note));
	if (params()->death)
	{
		even_philosopher_first_con(p);
		return (1);
	}
	pthread_mutex_unlock(&(params()->death_note));
	printf("%lu philosopher %d picked a fork\n", fix_time(), p->id);
	pthread_mutex_unlock(&(params()->print_lock));
	pthread_mutex_lock(&(params()->death_note));
	if (params()->death)
	{
		pthread_mutex_unlock(&(params()->death_note));
		pthread_mutex_unlock(&(p->right->mtx));
		return (1);
	}
	even_philosopher_non_con(p);
	if (params()->death)
	{
		even_philosopher_second_con(p);
		return (1);
	}
	return (pthread_mutex_unlock(&(params()->death_note)));
}
