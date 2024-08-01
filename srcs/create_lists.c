#include "../include/philosophers.h"

void	create_forks(void)
{
	int	i;

	i = 0;
	params()->list_f = malloc((sizeof(t_fork *))
		*(params()->number_of_philosophers + 1));
	if (!(params()->list_f))
		return ;
	while (i < params()->number_of_philosophers)
	{
		params()->list_f[i] = malloc((sizeof(t_fork)) * 1);
		if (!(params()->list_f[i]))
		{
			clean_forks();
			return ;
		}
		params()->list_f[i]->id = i + 1;
		pthread_mutex_init(&(params()->list_f[i]->mtx), NULL);
		i++;
	}
	params()->list_f[i] = NULL;
}

void	create_philosopher_thread(int i)
{
	if (i == 0)
		params()->list_p[i]->left = params()->\
				list_f[params()->number_of_philosophers - 1];
	else
		params()->list_p[i]->left = params()->list_f[i - 1];
	params()->list_p[i]->right = params()->list_f[i];
	params()->list_p[i]->number_of_meals = 0;
	params()->list_p[i]->last_meal = 0;
	if (pthread_create(&(params()->list_p[i]->thread), NULL, start,
			(params()->list_p[i])))
	{
		join_philosophers();
		clean();
		return ;
	}
}

void	create_philosophers(void)
{
	int	i;

	i = 0;
	params()->list_p = malloc((sizeof(t_philosopher *))
		*(params()->number_of_philosophers + 1));
	while (i < params()->number_of_philosophers)
	{
		params()->list_p[i] = malloc((sizeof(t_philosopher)) * 1);
		if (!(params()->list_p[i]))
		{
			params()->list_p[i] = NULL;
			clean();
			return ;
		}
		params()->list_p[i]->id = i + 1;
		create_philosopher_thread(i);
		i++;
	}
	params()->list_p[i] = NULL;
}

void	join_philosophers(void)
{
	int	i;

	i = 0;
	while (i < params()->number_of_philosophers)
	{
		if (pthread_join(params()->list_p[i]->thread, NULL))
			return ;
		i++;
	}
}
