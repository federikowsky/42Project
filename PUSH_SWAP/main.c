/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 21:30:43 by fefilipp          #+#    #+#             */
/*   Updated: 2022/02/20 03:22:21 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	push_atoi(const char *str)
{
	long int	num;
	int			i;
	long int	s;	

	num = 0;
	i = 0;
	s = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i])
		num = num * 10 + (str[i++] - '0');
	s *= num;
	return (s);
}

int	check_double(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc)
		{
			if (i != j)
			{
				if (push_atoi(argv[i]) == push_atoi(argv[j]))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_error(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 2)
		exit (1);
	while (i < argc)
	{	
		j = 0;
		while ((size_t)j < ft_strlen(argv[i]))
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				return (0);
			j++;
		}
		if (push_atoi(argv[i]) < -2147483648 || push_atoi(argv[i]) > 2147483647)
			return (0);
		i++;
	}
	return (check_double(argc, argv));
}

int	main(int argc, char **argv)
{
	t_ptr	k;
	t_ptr	b;
	int		*array;

	k = NULL;
	b = NULL;
	if (!check_error(argc, argv))
	{
		write(1, "Error\n", 6);
		exit (1);
	}
	k = alloca_nodo(argc, argv);
	if (check_is_sort(k))
		return (0);
	if (scl_len(k) <= 3)
	{
		ft_sort_remaining_a(&k);
		return (0);
	}
	array = ft_list_to_array(k);
	sort_array(array, scl_len(k));
	assigne_pos(k, array, scl_len(k));
	ft_sorting_a(&k, &b, array, scl_len(k));
}
