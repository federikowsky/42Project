/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:13:36 by fefilipp          #+#    #+#             */
/*   Updated: 2022/02/17 17:46:10 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ptr	ft_max_pos(t_ptr scl)
{
	t_ptr	res;

	res = scl;
	while (scl != NULL)
	{
		if (scl->pos > res->pos)
			res = scl;
		scl = scl->next;
	}
	return (res);
}

void	ft_go_back_b(t_ptr *a, t_ptr *b)
{
	t_ptr	temp;

	while (*b != NULL)
	{
		temp = ft_max_pos(*b);
		bring_to_top_value_b(b, temp->info);
		ft_push_b_a(b, a);
	}
}
