/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 01:23:50 by fefilipp          #+#    #+#             */
/*   Updated: 2022/02/18 03:04:26 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ptr	alloca_nodo(int argc, char **argv)
{
	int		i;
	t_ptr	res;
	t_ptr	temp;

	res = (t_ptr)malloc(sizeof(t_list));
	res->info = push_atoi(argv[1]);
	res->next = NULL;
	temp = res;
	i = 2;
	while (i < argc)
	{
		res->next = (t_ptr)malloc(sizeof(t_list));
		res = res->next;
		res->info = push_atoi(argv[i]);
		i++;
	}
	res->next = NULL;
	return (temp);
}

int	scl_len(t_ptr scl)
{
	if (scl == NULL)
		return (0);
	else
		return (1 + scl_len(scl->next));
}

void	assigne_pos(t_ptr scl, int a[], int n)
{
	int		i;
	t_ptr	temp;

	i = 0;
	temp = scl;
	while (i < n)
	{
		temp = scl;
		while (temp != NULL)
		{
			if (temp->info == a[i])
			{
				temp->pos = i;
				break ;
			}
			temp = temp->next;
		}
		i++;
	}
}

int	check_is_sort(t_ptr scl)
{
	t_ptr	temp;

	if (scl == NULL || scl->next == NULL)
		return (1);
	while (scl->next != NULL)
	{
		temp = scl->next;
		while (temp != NULL)
		{
			if (temp->info < scl->info)
				return (0);
			temp = temp->next;
		}
	scl = scl->next;
	}
	return (1);
}

t_ptr	ft_find_pos(t_ptr scl, int pos)
{
	t_ptr	res;

	res = NULL;
	while (scl != NULL)
	{
		if (scl->pos == pos)
			res = scl;
		scl = scl->next;
	}
	return (res);
}
