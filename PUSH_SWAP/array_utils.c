/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:29:07 by fefilipp          #+#    #+#             */
/*   Updated: 2022/02/20 02:59:08 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void	sort_array(int arr[], int n)
{
	int	i;
	int	j;
	int	swapped;

	i = 0;
	while (i < n - 1)
	{
		swapped = 0;
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				swapped = 1;
			}
			j++;
		}
		if (swapped == 0)
			break ;
		i++;
	}
}

int	*ft_list_to_array(t_list *stack_a)
{
	int		*array;
	int		i;
	int		list_size;
	t_list	*temp;

	i = 0;
	list_size = scl_len(stack_a);
	if (stack_a == NULL)
		return (NULL);
	array = malloc(sizeof(int) * list_size + 1);
	temp = stack_a;
	while (temp)
	{
		array[i] = temp->info;
		temp = temp->next;
		i++;
	}
	return (array);
}

int	find_median(int n)
{
	if (n % 2 == 0)
		return (n / 2);
	else
		return ((n - 1) / 2);
}
