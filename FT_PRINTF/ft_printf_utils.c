/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 21:54:08 by pcatapan          #+#    #+#             */
/*   Updated: 2022/01/30 19:32:59 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
		ft_char(s[i++]);
	return (i);
}

int	ft_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_percentage(const char **s)
{
	ft_char(**s);
	(*s)++;
	return (1);
}
