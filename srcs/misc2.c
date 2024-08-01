#include "../include/philosophers.h"

void	odd_philosopher_first_con(t_philosopher *p)
{
	pthread_mutex_unlock(&(params()->death_note));
	pthread_mutex_unlock(&(params()->print_lock));
	pthread_mutex_unlock(&(p->left->mtx));
}

void	odd_philosopher_non_con(t_philosopher *p)
{
	pthread_mutex_unlock(&(params()->death_note));
	pthread_mutex_lock(&(p->right->mtx));
	pthread_mutex_lock(&(params()->print_lock));
	pthread_mutex_lock(&(params()->death_note));
}

void	odd_philosopher_second_con(t_philosopher *p)
{
	pthread_mutex_unlock(&(params()->death_note));
	pthread_mutex_unlock(&(p->left->mtx));
	pthread_mutex_unlock(&(params()->print_lock));
	pthread_mutex_unlock(&(p->right->mtx));
}
