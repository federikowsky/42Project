/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 00:33:38 by fefilipp          #+#    #+#             */
/*   Updated: 2023/04/02 19:35:22 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
    size_t i;
    if ((uintptr_t)b % sizeof(long) == 0 &&
        len % sizeof(long) == 0)
    {

        long *d = b;

        for (i = 0; i < len / sizeof(long); i++)
        {
            d[i] = (char) c;
        }
    }
    else
    {
        char *d = b;

        for (i = 0; i < len; i++)
        {
            d[i] = (char) c;
        }
    }

    return b;
}
