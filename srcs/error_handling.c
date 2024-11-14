/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasdouq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:34:19 by amasdouq          #+#    #+#             */
/*   Updated: 2024/08/01 13:34:21 by amasdouq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	check_for_non_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (1);
		i++;
	}
	return (0);
}

int	check_numbers_validity(char *str)
{
	unsigned long	num;

	num = (unsigned long)atol(str);
	if (strlen(str) >= 20)
		return (1);
	return (0);
}

int	error_handling(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (check_for_non_digits(av[i]) || check_numbers_validity(av[i]))
			return (1);
		i++;
	}
	return (0);
}

int	error_handling2()
{
  if (params()->number_of_philosophers <= 0 \
    || params()->number_of_philosophers > 250 \
    || params()->time_to_die <= 0 \
    || params()->time_to_eat <= 0 \
    || params()->time_to_sleep <= 0 \
    || (params()->number_of_times_philosopher_must_eat <= 0
  && params()->ac == 6))
  {
    printf("Error11\n");
    return (1);
  }
  return (0);
}
