/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_list2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 23:27:55 by fefilipp          #+#    #+#             */
/*   Updated: 2022/02/17 13:41:56 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	inverte i primi due elementi
void	ft_swap_b(t_ptr	*lst)
{
	t_ptr	temp;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	temp = *lst;
	*lst = (*lst)->next;
	temp->next = (*lst)->next;
	(*lst)->next = temp;
	write(1, "sb\n", 3);
}

//	il primo diventa l'ultimo
void	ft_rotate_b(t_ptr *lst)
{
	t_ptr	temp_first;
	t_ptr	temp_second;

	temp_first = *lst;
	temp_second = (*lst)->next;
	while ((*lst)->next != NULL)
		(*lst) = (*lst)->next;
	(*lst)->next = temp_first;
	temp_first->next = NULL;
	*lst = temp_second;
	write(1, "rb\n", 3);
}

//	ultimo elemento diventa il primo
void	ft_reverse_rotate_b(t_ptr *lst)
{
	t_ptr		temp;
	t_ptr		ttt;

	temp = *lst;
	while (temp->next->next != NULL)
		temp = temp->next;
	ttt = temp;
	temp = temp->next;
	temp->next = *lst;
	(*lst) = temp;
	ttt->next = NULL;
	write(1, "rrb\n", 4);
}

//	switcha nodo da A a B
void	ft_push_b_a(t_ptr *b, t_ptr *a)
{
	t_ptr	temp;

	if (*b == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	write(1, "pb\n", 3);
}

//	scambia primi elementi di A e di B
void	ft_double_swap_a_b(t_ptr *a, t_ptr *b)
{
	ft_swap_b(b);
	ft_swap_a(a);
	write(1, "ss\n", 3);
}
