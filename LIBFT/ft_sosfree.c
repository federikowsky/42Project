/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sosfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:07:26 by fefilipp          #+#    #+#             */
/*   Updated: 2023/04/03 00:49:01 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
free the input matrix 
*/
int	ft_sosfree(char **ss)
{
	char	**p;

    if (!ss)
        return (0);
    p = ss;
    while (*p)
    {
        free(*p);
        *p = NULL;
        ++p;
    }
    free(ss);
    return (1);
}
