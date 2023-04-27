/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlocc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:38:43 by fefilipp          #+#    #+#             */
/*   Updated: 2022/11/27 20:42:20 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
Returns the index of the last occurrence of a char 
passed as argument from the starting position
if not found -1 is returned
*/
int	ft_strlocc(char *s, int start, int c)
{
	int	found;

	found = -1;
	while (s[start])
	{
		if (s[start] == c)
			found = start;
		start++;
	}
	return (found);
}