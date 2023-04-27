/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdi-russ <rdi-russ@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:54:46 by rdi-russ          #+#    #+#             */
/*   Updated: 2022/01/26 11:56:44 by rdi-russ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *param, ...);
int		ft_putchar(char c);
int		ft_printchar(va_list arg);
int		ft_printhexalower(va_list arg);
int		ft_printhexaupper(va_list arg);
int		ft_printinteger(va_list arg);
int		ft_printpercent(char c);
int		ft_printptr(va_list arg);
int		ft_printstring(va_list arg);
int		ft_printunsint(va_list arg);
int		ft_putnbr_hexalower(unsigned int nb);
int		ft_putnbr_hexaupper(unsigned int nb);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
size_t	ft_strlen(const char *s);

#endif