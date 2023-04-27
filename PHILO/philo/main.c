/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 23:41:17 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/09/20 03:08:45 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error_handling(int argc, char **argv, t_main *main)
{
	if (argc == 2 && !philo_strncmp(argv[1], "help", 4)
		&& philo_strlen(argv[1]) == 4)
	{
		printf("error \n");
		return (0);
	}
	else if (init_input_struct(argc, argv, main) == 0)
	{
		printf("error \n");
		return (0);
	}
	else
	{
		if (!main->input.num_philo || !main->input.time_to_die
			|| !main->input.time_to_eat || !main->input.time_to_sleep
			|| (argc == 6 && !main->input.num_of_times_eat))
			return (0);
	}
	return (1);
}

int	init_input_struct(int argc, char **argv, t_main *main)
{
	if (argc == 5 || argc == 6)
	{
		main->input.num_philo = philo_atoi(argv[1]);
		main->input.time_to_die = philo_atoi(argv[2]);
		main->input.time_to_eat = philo_atoi(argv[3]);
		main->input.time_to_sleep = philo_atoi(argv[4]);
		if (argc == 6)
			main->input.num_of_times_eat = philo_atoi(argv[5]);
		else
			main->input.num_of_times_eat = -1;
		return (1);
	}
	return (0);
}

int	just_one_philo(t_main *main)
{
	if (pthread_mutex_init(&main->write, NULL) != 0)
		return (0);
	main->t0 = get_time();
	philo_print(main, 1, FORK);
	exec_action(main->input.time_to_die);
	philo_print(main, 1, DIED);
	philo_free(main);
	return (1);
}

int	main(int argc, char **argv)
{
	t_main	main;

	if (error_handling(argc, argv, &main) == 0)
		return (1);
	if (create_philos(&main) == 0)
		return (1);
	if (create_forks(&main) == 0)
		return (1);
	if (main.input.num_philo == 1)
	{
		if (just_one_philo(&main) == 0)
			return (1);
		return (0);
	}
	if (create_threads(&main) == 0)
		return (1);
	if (destroy_threads(&main) == 0)
		return (1);
	philo_free(&main);
	return (0);
}
