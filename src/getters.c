/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:06:40 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/05/29 21:24:35 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_list *stack)
{
	int	count;

	if (stack)
	{
		while (stack->next)
		{
			count++;
			stack = stack->next;
		}
	}
	return (count);
}