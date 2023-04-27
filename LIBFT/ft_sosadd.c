/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sosadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:19:56 by fefilipp          #+#    #+#             */
/*   Updated: 2023/04/03 00:48:52 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
take 1 * N matrix where N is number of 
allocated and stored string and
copies the input matrix and adds the string passed 
as argument in a matrix allocated with malloc(). 
Free the old matrix and return a pointer to the new matrix
*/
char **ft_sosadd(char **ss, char *s)
{
	char	**res;
	int		len;

    if (!ss)
	{
		len = 0;
        res = (char **)malloc(2 * sizeof(char *));
	}
	else
	{
		len = ft_soslen(ss);
		res = (char **)realloc(ss, (len + 2) * sizeof(char *));
	}
	if (!res)
	{
		ft_sosfree(ss);
		return NULL;
	}
	*(res + len) = s;
    *(res + len + 1) = NULL;
	return res;
}
