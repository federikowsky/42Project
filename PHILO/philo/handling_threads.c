/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 23:00:12 by anolivei          #+#    #+#             */
/*   Updated: 2022/09/20 03:56:25 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_threads(t_main *main)
{
	int	i;

	i = 0;
	main->philo_dead = 0;
	main->t0 = get_time();
	if (pthread_mutex_init(&main->write, NULL) != 0)
		return (0);
	while (i < main->input.num_philo)
	{
		main->n_thread = i;
		if (pthread_create(&main->philo[i].thread,
				NULL, &routine, (void *) main) != 0)
			return (0);
		i++;
		usleep(1000);
	}
	if (pthread_create(&main->orchestrator, NULL, &checker, (void *) main) != 0)
		return (0);
	usleep(1000);
	if (join_threads(main) == 0)
		return (0);
	return (1);
}

int	join_threads(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->input.num_philo)
	{
		if (pthread_join(main->philo[i].thread, NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_join(main->orchestrator, NULL) != 0)
		return (0);
	return (1);
}

int	destroy_threads(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->input.num_philo)
	{
		pthread_mutex_destroy(&main->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&main->write);
	return (1);
}
