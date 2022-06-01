/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 09:31:04 by rpoder            #+#    #+#             */
/*   Updated: 2022/06/01 15:34:22 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(t_list *stack)
{
	t_list	*to_compare;

	while (stack)
	{
		to_compare = stack->next;
		while (to_compare)
		{
			if (((t_info *)to_compare->content)->number
				== ((t_info *)stack->content)->number)
				return (1);
			to_compare = to_compare->next;
		}
		stack = stack->next;
	}
	return (0);
}

int	check_is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (!(((t_info *)stack->content)->number
				< ((t_info *)stack->next->content)->number))
			return (0);
		stack = stack->next;
	}
	return (1);
}
