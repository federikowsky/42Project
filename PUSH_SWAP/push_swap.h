/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 21:25:04 by fefilipp          #+#    #+#             */
/*   Updated: 2022/02/20 02:59:01 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

/*****************************   BASE FUNCTION   *****************************/

void	ft_rotate_a(t_ptr *lst);
void	ft_rotate_b(t_ptr *lst);
void	ft_reverse_rotate_a(t_ptr *lst);
void	ft_reverse_rotate_b(t_ptr *lst);
void	ft_push_a_b(t_ptr *a, t_ptr *b);
void	ft_push_b_a(t_ptr *b, t_ptr *a);
void	ft_swap_b(t_ptr	*lst);
void	ft_swap_a(t_ptr	*lst);
void	ft_double_swap_a_b(t_ptr *a, t_ptr *b);

/*****************************   BASE FUNCTION   *****************************/

int		check_is_sort(t_ptr scl);
void	print_scl(t_ptr scl);
int		scl_len(t_ptr scl);
// t_ptr	alloca_nodo(t_ptr scl, t_tipoinfo val);
t_ptr	alloca_nodo(int argc, char **argv);
void	del_node(t_ptr lst, t_ptr node);
void	print_pos(t_ptr scl);
void	assigne_pos(t_ptr scl, int a[], int n);
t_ptr	ft_find_pos(t_ptr scl, int pos);
int		*st_to_int(char **argv, int n);
int		*ft_list_to_array(t_list *stack_a);

/*****************************   BASE FUNCTION   *****************************/

long	push_atoi(const char *str);
void	sort_array(int arr[], int n);
void	swap(int *xp, int *yp);
void	print_array(int a[], int n);
int		find_median(int n);

/*****************************   BASE FUNCTION   *****************************/

void	bring_to_top_value_a(t_ptr *scl, int val);
void	bring_to_top_value_b(t_ptr *scl, int val);
int		from_bottom(t_ptr a, int val);
int		from_up(t_ptr a, int val);
void	ft_move_from_a_to_b(t_ptr *a, t_ptr *b, int array[], int n);
void	ft_move(t_ptr *a, t_ptr *b, int val);
void	ft_first_move(t_ptr *a, t_ptr *b, int arr[], int n);
void	ft_sort_remaining_a(t_ptr *a);
int		ft_stop_switching(t_ptr a, int val);
int		ft_stop_switching2(t_ptr a, int lower, int upper);
t_ptr	ft_max_pos(t_ptr scl);
void	ft_go_back_b(t_ptr *a, t_ptr *b);
void	ft_sorting_a(t_ptr *a, t_ptr *b, int array[], int n);
void	ft_sort_quarter(t_ptr *a, t_ptr *b, int arr[], int n);
int		*ft_sub_array(int arr[], int start, int end);
#endif