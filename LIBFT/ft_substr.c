/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:06:16 by fefilipp          #+#    #+#             */
/*   Updated: 2023/04/02 19:36:54 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Return a substring of s having len bytes from start
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
    char            *temp;
	unsigned int	lenght;

	if (!s)
		return (NULL);
	lenght = ft_strlen(s);
	if (lenght <= len)
		sub = (char *)malloc(sizeof(char) * lenght + 1);
	else
		sub = (char *)malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
    s = s + start;
    temp = sub;
	while (*s && len-- > 0)
		*temp++ = *s++;
	*temp = '\0';
	return (sub);
}
