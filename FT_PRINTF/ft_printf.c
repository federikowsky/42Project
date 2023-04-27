/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:18:14 by pcatapan          #+#    #+#             */
/*   Updated: 2023/04/02 19:26:04 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	aux_printf(va_list var, const char *str)
{
	int		count;

	count = 0;
	while (*str)
	{
		if (*str == 's')
			count += ft_write(va_arg(var, char *));
		else if (*str == 'c')
			count += ft_char(va_arg(var, int));
		else if (*str == 'd' || *str == 'i')
			count += aux_nbr_base(va_arg(var, int), *str);
		else if (*str == 'u')
			count += aux_nbr_base(va_arg(var, unsigned int), *str);
		else if (*str == 'x' || *str == 'X')
			count += aux_nbr_base(va_arg(var, int), *str);
		else if (*str == 'p')
			count += print_address(va_arg(var, uintptr_t));
		else if (*str == '%' && *(str + 1) == '%')
			count += ft_percentage(&str);
		else if (*str != '%')
			count += ft_char(*str);
		str++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	var;

	count = 0;
	va_start(var, str);
	while (*str != '%')
		count += ft_char(*str++);
	count += aux_printf(var, str);
	va_end(var);
	return (count);
}

// int		main()
// {
// 	int x = 5;
// 	printf("standard: %d", printf(" %c %c %c ", '0', 0, '1'));
// 	printf("\n");
// 	ft_printf("mia funz:%d", ft_printf(" %c %c %c ", '0', 0, '1'));

// }