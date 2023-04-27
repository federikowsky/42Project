/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 02:11:09 by fefilipp          #+#    #+#             */
/*   Updated: 2023/04/02 19:35:59 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The strdup() function allocates sufficient memory 
for a copy of the string s1, does the copy, 
and returns a pointer to it
*/
char	*ft_strdup(const char *s)
{
	int		len;
	char	*res;
	len = ft_strlen(s) + 1;
	res = malloc(len);
	if (res)
		ft_memcpy(res, s, len);
	return (res);
}
