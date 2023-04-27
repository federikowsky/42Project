/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexalower.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:55:43 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/01/26 11:55:44 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexalower(unsigned int nb)
{
	char	*hexa;
	int		output;

	hexa = "0123456789abcdef";
	output = 0;
	if (nb > 15)
		output += output + ft_putnbr_hexalower(nb / 16);
	output += write(1, &hexa[nb % 16], 1);
	return (output);
}
