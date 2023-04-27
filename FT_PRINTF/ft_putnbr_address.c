/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:33:58 by fefilipp          #+#    #+#             */
/*   Updated: 2022/01/30 19:34:08 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_address(uintptr_t n, char *base, int len_base)
{
	if (n >= (unsigned long) len_base)
	{
		ft_putnbr_address(n / len_base, base, len_base);
		ft_char(base[n % len_base]);
	}
	else if (n >= 0 && n < (unsigned long) len_base)
		ft_char(base[n % len_base]);
	else if (n < 0)
	{
		ft_char('-');
		ft_putnbr_address(-n, base, len_base);
	}
}

int	len_nbr_address(uintptr_t n, int base)
{
	int	res;

	res = 0;
	if (n < 0)
	{
		n *= -1;
		res++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / base;
		res++;
	}
	return (res);
}

int	print_address(uintptr_t n)
{
	write (1, "0x", 2);
	ft_putnbr_address(n, "0123456789abcdef", 16);
	return (2 + len_nbr_address(n, 16));
}
