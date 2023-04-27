/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 00:29:27 by fefilipp          #+#    #+#             */
/*   Updated: 2023/04/03 00:07:53 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
    size_t i;
    if ((uintptr_t)dst % sizeof(long) == 0 &&
        (uintptr_t)src % sizeof(long) == 0 &&
        len % sizeof(long) == 0)
    {

        long *d = dst;
        const long *s = src;

        for (i = 0; i < len / sizeof(long); i++)
        {
            d[i] = s[i];
        }
    }
    else
    {
        char *d = dst;
        const char *s = src;

        for (i = 0; i < len; i++)
        {
            d[i] = s[i];
        }
    }
    return dst;
}
