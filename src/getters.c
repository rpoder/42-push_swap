/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:06:40 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/05/31 18:40:05 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_list *stack)
{
	int		count;
	t_list	*tmp;

	count = 0;
	tmp = stack;
	if (tmp)
	{
		while (tmp)
		{
			count++;
			tmp = tmp->next;
		}
	}
	return (count);
}
