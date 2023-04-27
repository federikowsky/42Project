/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_soslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:10:36 by fefilipp          #+#    #+#             */
/*   Updated: 2023/04/02 23:48:17 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
take 1 * N matrix where N is number of 
allocated and stored string and
Return number of string allocated in matrix
*/

int	ft_soslen(char **ss)
{
	char	**end;

	if (!ss)
		return (0);
	end = ss;
	while (*end)
		++end;
	return (end - ss);
}
