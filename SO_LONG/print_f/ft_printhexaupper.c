/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexaupper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:54:59 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/01/26 11:55:00 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexaupper(va_list arg)
{
	unsigned int	nb;

	nb = va_arg(arg, unsigned int);
	return (ft_putnbr_hexaupper(nb));
}
