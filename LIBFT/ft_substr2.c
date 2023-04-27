/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:17:34 by fefilipp          #+#    #+#             */
/*   Updated: 2022/11/08 23:18:03 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Return a substring of s from start to end exclude
*/
char	*ft_substr2(const char *s, int start, int end)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (end - start));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}