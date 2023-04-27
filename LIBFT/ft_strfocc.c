/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfocc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:47:49 by fefilipp          #+#    #+#             */
/*   Updated: 2022/11/27 20:42:12 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
Returns the index of the first occurrence of a char 
passed as argument from the starting position
if not found -1 is returned
*/
int	ft_strfocc(char *s, int start, int c)
{
	while (s[start])
	{
		if (s[start] == c)
			return (start);
		start++;
	}
	return (-1);
}