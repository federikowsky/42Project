/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:30:11 by fefilipp          #+#    #+#             */
/*   Updated: 2022/11/08 23:33:51 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(unsigned int n, int base)
{
	char	*base_set;
	int		i;
	
	base_set = "0123456789abcdef";
	i = n % base;
	if (n / base > 0)
		ft_putnbr(n / base, base);
	ft_putchar_fd(base_set[i], 1);
}