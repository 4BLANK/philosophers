#include "../include/philosophers.h"

void	clean_philosophers(void)
{
	int	i;

	i = 0;
	while ((params()->list_p[i]))
	{
		free(params()->list_p[i]);
		params()->list_p[i++] = NULL;
	}
	free(params()->list_p);
	params()->list_p = NULL;
}

void	clean_forks(void)
{
	int	i;

	i = 0;
	while ((params()->list_f[i]))
	{
		pthread_mutex_destroy(&(params()->list_f[i]->mtx));
		free(params()->list_f[i]);
		params()->list_f[i++] = NULL;
	}
	free(params()->list_f);
	params()->list_f = NULL;
}

int	clean(void)
{
	if (params()->list_f)
	{
		clean_forks();
	}
	if (params()->list_p)
	{
		clean_philosophers();
	}
	return (0);
}
