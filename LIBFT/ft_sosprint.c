/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sosprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:12:28 by fefilipp          #+#    #+#             */
/*   Updated: 2023/04/02 23:48:11 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sosprint(char **ss)
{
	while (*ss)
	{
		// printf("%s\n", ss[i]);
		write(1, *ss, ft_strlen(*ss));
		write(1, "\n", 1);
		++ss;
	}
}