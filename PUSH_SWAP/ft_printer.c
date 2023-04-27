/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 03:03:25 by fefilipp          #+#    #+#             */
/*   Updated: 2022/02/17 16:38:21 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_scl(t_ptr scl)
{
	if (scl != NULL)
	{
		printf("%d ", scl->info);
		print_scl(scl->next);
	}
	else
		printf("\n\n");
}

void	print_pos(t_ptr scl)
{
	if (scl != NULL)
	{
		printf("%d ", scl->pos);
		print_pos(scl->next);
	}
	else
		printf("\n\n");
}

void	print_array(int a[], int n)
{
	int	i;

	i = 0;
	while (n-- > 0)
	{
		printf("%d ", a[i]);
		i++;
	}
	printf("\n\n");
}
