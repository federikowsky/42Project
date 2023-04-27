/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:55:26 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/01/26 11:55:27 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstring(va_list arg)
{
	char	*str;

	str = va_arg(arg, char *);
	if (!str)
		return (write(1, "(null)", 6));
	ft_putstr(str);
	return (ft_strlen(str));
}
