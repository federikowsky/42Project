/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 00:34:34 by fefilipp          #+#    #+#             */
/*   Updated: 2023/04/02 19:36:17 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	res;
// 	char	*temp_dst;
// 	char	*temp_src;

// 	res = 0;
// 	temp_dst = (char *)dst;
// 	temp_src = (char *)src;
// 	while (*temp_dst)
// 		temp_dst++;
// 	res += temp_dst - dst;
// 	while ((temp_dst - dst < (long)(dstsize - 1)) && *temp_src)
// 		*temp_dst++ = *temp_src++;
// 	*temp_dst = 0;
// 	while (*temp_src)
// 		temp_src++;
// 	res += temp_src - src;
// 	return (res);
// }
size_t	ft_strlcat(char *dst, const char *src, size_t destsize)
{
	size_t	i;
	size_t	j;
	size_t	x;

	i = ft_strlen(dst);
	j = ft_strlen((char *)src);
	x = 0;
	if (destsize <= i)
		x = j + destsize;
	else
		x = j + i;
	j = 0;
	while (src[j] != '\0' && i + 1 < destsize)
		dst[i++] = src[j++];
	if (j > 0)
		dst[i] = '\0';
	return (x);
}
