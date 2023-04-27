/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exchange_lists.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:39:55 by fefilipp          #+#    #+#             */
/*   Updated: 2022/02/20 03:04:15 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stop_switching(t_ptr a, int val)
{
	while (a != NULL)
	{
		if (a->info < val)
			break ;
		a = a->next;
	}
	if (a == NULL)
		return (0);
	return (1);
}

void	ft_sort_remaining_a(t_ptr *a)
{
	int	*array;

	if (scl_len(*a) == 2)
	{
		if ((*a)->info > (*a)->next->info)
			ft_swap_a(a);
		return ;
	}
	array = ft_list_to_array(*a);
	sort_array(array, scl_len(*a));
	bring_to_top_value_a(a, array[scl_len(*a) / 2]);
	free(array);
	if ((*a)->next->info > (*a)->next->next->info)
		ft_reverse_rotate_a(a);
	else
		ft_swap_a(a);
}

void	ft_first_move(t_ptr *a, t_ptr *b, int arr[], int n)
{
	int		start_value;
	int		cond;

	bring_to_top_value_a(a, arr[n / 2]);
	ft_push_a_b(a, b);
	start_value = (*b)->info;
	// start_value = arr[n / 2];
	cond = 1;
	while (cond)
	{
		if ((*a)->info < arr[n])
		{
			ft_push_a_b(a, b);
			if ((*b)->info < start_value)
				ft_rotate_b(b);
		}
		else
			ft_rotate_a(a);
		cond = ft_stop_switching(*a, arr[n]);
	}
}

void	ft_move(t_ptr *a, t_ptr *b, int val)
{
	int		cond;

	cond = 1;
	while (cond)
	{
		if ((*a)->info < val)
			ft_push_a_b(a, b);
		else
			ft_rotate_a(a);
		cond = ft_stop_switching(*a, val);
	}
}

void	ft_move_from_a_to_b(t_ptr *a, t_ptr *b, int array[], int n)
{
	t_ptr	temp;

	temp = *a;
	while (scl_len(*a) > 3)
	{
		if (*b == NULL)
			ft_first_move(a, b, array, n / 2);
		free(array);
		array = ft_list_to_array(*a);
		sort_array(array, scl_len(*a));
		ft_move(a, b, array[scl_len(*a) / 2]);
	}
	ft_sort_remaining_a(a);
}
