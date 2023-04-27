/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefilipp <fefilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 02:07:44 by fefilipp          #+#    #+#             */
/*   Updated: 2022/01/26 21:34:01 by fefilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!lst || !del || (*lst) == NULL)
		return ;
	ft_lstclear(&(*lst)->next, del);
	del((*lst)->content);
	free((*lst));
	*lst = NULL;
}
