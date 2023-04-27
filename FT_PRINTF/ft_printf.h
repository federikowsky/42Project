/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:24:12 by fefilipp          #+#    #+#             */
/*   Updated: 2022/01/30 19:31:53 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		aux_nbr_base(long int n, char c);
int		len_nbr_base(long int n, int base);
void	ft_putnbr_base(long int n, char *base, int len_base);
int		ft_write(char *s);
int		ft_char(char c);
int		aux_printf(va_list var, const char *s);
int		print_address(uintptr_t n);
int		len_nbr_address(uintptr_t n, int base);
void	ft_putnbr_address(uintptr_t n, char *base, int len_base);
int		ft_percentage(const char **s);

#endif