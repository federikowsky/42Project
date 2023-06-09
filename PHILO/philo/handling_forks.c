/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_forks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 02:13:13 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/09/20 02:13:33 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_forks(t_main *main)
{
	int	i;

	main->forks = malloc(sizeof(pthread_mutex_t) * main->input.num_philo + 1);
	if (main->forks == NULL)
		return (0);
	i = 0;
	while (i < main->input.num_philo)
	{
		if (pthread_mutex_init(&main->forks[i], NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

void	unlock_forks(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->input.num_philo)
	{
		pthread_mutex_unlock(&main->forks[i]);
		i++;
	}
}
