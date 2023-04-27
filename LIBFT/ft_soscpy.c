/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_soscpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:13:00 by fefilipp          #+#    #+#             */
/*   Updated: 2023/04/02 23:52:19 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
take 1 * N matrix where N is number of 
allocated and stored string and
allocate a new matrix then copy the input matrix 
and return a pointer to it.
*/
char	**ft_soscpy(char **ss)
{
	char	**res;
	int		i;
	size_t	len;

	res = (char **)malloc(sizeof(char *) * ft_soslen(ss));
	if (!res)
		return (NULL);

	i = -1;
	while (ss[++i])
	{
		len = ft_strlen(ss[i]);
        res[i] = (char *)malloc(len + 1);
        if (!res[i])
        {
            ft_sosfree(res);
            return (NULL);
        }
        ft_memcpy(res[i], ss[i], len + 1);
	}
	res[i] = NULL;
	return (res);
}