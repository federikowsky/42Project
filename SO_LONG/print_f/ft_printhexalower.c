/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexalower.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:54:53 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/01/26 11:54:54 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexalower(va_list arg)
{
	unsigned int	nb;

	nb = va_arg(arg, unsigned int);
	return (ft_putnbr_hexalower(nb));
}
