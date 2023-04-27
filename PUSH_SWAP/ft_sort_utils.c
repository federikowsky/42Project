/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:27:01 by fefilipp          #+#    #+#             */
/*   Updated: 2022/02/18 01:08:48 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	from_up(t_ptr a, int val)
{
	int	i;

	i = 0;
	while (a != NULL && a->info != val)
	{
		i++;
		a = a->next;
	}
	if (a == NULL)
		return (0);
	return (i);
}

int	from_bottom(t_ptr a, int val)
{
	int		i;
	t_ptr	temp;

	temp = a;
	i = 0;
	while (temp != NULL && temp->info != val)
	{
		i++;
		temp = temp->next;
	}
	if (temp == NULL)
		return (0);
	return (scl_len(a) - i);
}

void	bring_to_top_value_a(t_ptr *scl, int val)
{
	int	move;

	move = 0;
	if (from_up(*scl, val) < from_bottom(*scl, val))
	{
		move = from_up(*scl, val);
		while (move-- > 0)
		{
			ft_rotate_a(scl);
		}
	}
	else
	{
		move = from_bottom(*scl, val);
		while (move-- > 0)
		{
			ft_reverse_rotate_a(scl);
		}
	}
}

void	bring_to_top_value_b(t_ptr *scl, int val)
{
	int	move;

	if (from_up(*scl, val) < from_bottom(*scl, val))
	{
		move = from_up(*scl, val);
		while (move-- > 0)
		{
			ft_rotate_b(scl);
		}
	}
	else
	{
		move = from_bottom(*scl, val);
		while (move-- > 0)
		{
			ft_reverse_rotate_b(scl);
		}
	}
}
