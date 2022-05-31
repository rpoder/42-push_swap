/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:22:19 by rpoder            #+#    #+#             */
/*   Updated: 2022/05/31 16:23:56 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*todelete;

	if (!*lst || !del)
		return ;
	while (*lst)
	{
		todelete = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(todelete, del);
	}
	free(*lst);
}
