/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:18:52 by fefilipp          #+#    #+#             */
/*   Updated: 2023/04/02 19:35:54 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The strchr() function locates the first occurrence of c 
(converted to a char) in the string pointed to by s.
The terminating null character is
considered to be part of the string; therefore if c is ‘\0’,
the functions locate the terminating ‘\0’.
*/
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	return (0);
}
