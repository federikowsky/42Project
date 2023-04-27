/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:32:33 by fefilipp          #+#    #+#             */
/*   Updated: 2022/01/30 19:33:01 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(long int n, char *base, int len_base)
{
	if (len_base == 16)
	{
		n = (unsigned int) n;
		len_base = (unsigned int) len_base;
	}
	if (n >= len_base)
	{
		ft_putnbr_base(n / len_base, base, len_base);
		ft_char(base[n % len_base]);
	}
	else if (n >= 0 && n < len_base)
		ft_char(base[n % len_base]);
	else if (n < 0)
	{
		ft_char('-');
		ft_putnbr_base(-n, base, len_base);
	}
}

int	len_nbr_base(long int n, int base)
{
	int	res;

	res = 0;
	if (base == 16)
		n = (unsigned int) n;
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

int	aux_nbr_base(long int n, char c)
{
	if (c == 'x')
	{
		ft_putnbr_base((unsigned int)n, "0123456789abcdef", 16);
		return (len_nbr_base((unsigned int)n, 16));
	}
	if (c == 'X')
	{
		ft_putnbr_base((unsigned int)n, "0123456789ABCDEF", 16);
		return (len_nbr_base((unsigned int)n, 16));
	}
	else
	{
		ft_putnbr_base(n, "0123456789", 10);
		return (len_nbr_base(n, 10));
	}
}
