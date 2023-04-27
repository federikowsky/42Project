/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:55:33 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/01/26 11:55:34 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_countnumuns(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		count++;
		nb *= -1;
	}
	if (nb == 0)
		count++;
	while (nb > 0)
	{
		count++;
		nb = nb / 10;
	}
	return (count);
}

int	ft_printunsint(va_list arg)
{
	unsigned int	nb;

	nb = va_arg(arg, unsigned int);
	if (nb < 0)
	{
		nb = (4294967296 + nb);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else if (nb <= 9)
	{
		ft_putchar(nb + 48);
	}
	return (ft_countnumuns(nb));
}
