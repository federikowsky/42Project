/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:14:25 by fefilipp          #+#    #+#             */
/*   Updated: 2022/11/27 20:50:15 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
replaces every instance of find in src by replace.
*/
char	*ft_replace(char *src, char *find, char *replace)
{
	size_t		len;
	size_t		find_len;
	size_t		replace_len;
	char		*dest;
	char		*destptr;

	find_len = ft_strlen(find);
	replace_len = ft_strlen(replace);
	len = ft_strlen(src) - find_len + replace_len + 1;
	dest = malloc(len);
	destptr = dest;
	*dest = 0;
	while (*src)
	{
		if (!ft_strncmp(src, find, find_len))
		{
			strcat(destptr, replace);
			src += find_len;
			destptr += replace_len;
		}
		else
		{
			*destptr = *src;
			destptr++;
			src++;
		}
	}
	*destptr = 0;
	return (dest);
}