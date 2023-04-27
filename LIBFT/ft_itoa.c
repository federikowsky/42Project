/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:59:37 by fefilipp          #+#    #+#             */
/*   Updated: 2022/01/26 17:51:12 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	itoa_len(long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		i++;
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*itoa_aux(char *str, long nb, size_t len, int n)
{
	if (nb < 0)
	{
		nb = nb * -1;
		str[0] = '-';
	}
	str[len] = '\0';
	if (n == 0)
	{
		str[len - 1] = '0';
		return (str);
	}
	while (nb > 0)
	{
		str[--len] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (*(&str));
}

char	*ft_itoa(int n)
{
	char	*res;
	long	n2;
	size_t	len;

	len = itoa_len(n);
	n2 = n;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	return (itoa_aux(res, n2, len, n));
}
