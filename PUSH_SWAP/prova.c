/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prova.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:39:39 by fefilipp          #+#    #+#             */
/*   Updated: 2022/02/20 03:00:13 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_sub_array(int arr[], int end, int start)
{
	int	*res;
	int	i;

	i = 0;
	res = (int *)malloc(sizeof(int) * (end - start));
	while (end-- > start)
	{
		res[i] = arr[start + i];
		i++;
	}
	return (res);
}

int	ft_stop_switching2(t_ptr a, int lower, int upper)
{
	while (a != NULL)
	{
		if (a->info >= lower && a->info <= upper)
			break ;
		a = a->next;
	}
	if (a == NULL)
		return (0);
	return (1);
}

// pos_ptr = ft_find_pos(*b, (*a)->pos - 1);
// if (pos_ptr != NULL)
// 	bring_to_top_value_b(b, pos_ptr->info);
void	ft_sort_quarter(t_ptr *a, t_ptr *b, int arr[], int n)
{
	int		start_value;
	int		cond;

	start_value = arr[n / 2];
	cond = 1;
	while (cond)
	{
		if ((*a)->info <= arr[n - 1] && (*a)->info >= arr[0])
		{
			ft_push_a_b(a, b);
			if ((*b)->info < start_value && scl_len(*b) != 1)
				ft_rotate_b(b);
		}
		else
			ft_reverse_rotate_a(a);
		cond = ft_stop_switching2(*a, arr[0], arr[n - 1]);
	}
}

void	ft_sorting_a(t_ptr *a, t_ptr *b, int array[], int n)
{
	int	i;
	int	*temp_arr;
	int	start;
	int	end;

	i = 4;
	while (scl_len(*a) != n || !check_is_sort(*a))
	{
		end = (n / 4) * i--;
		start = (n / 4) * i;
		temp_arr = ft_sub_array(array, end, start);
		sort_array(temp_arr, end - start);
		ft_sort_quarter(a, b, temp_arr, end - start);
		bring_to_top_value_a(a, array[end]);
		ft_go_back_b(a, b);
	}
}
