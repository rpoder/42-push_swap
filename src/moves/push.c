/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:12:44 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/05/30 17:57:15 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stacks *stacks)
{
	t_list	*tmp;

	if (!stacks || !stacks->b)
		return;
	if (stacks->a)
	{
		tmp = stacks->b->next;
		stacks->b->next = stacks->a;
		stacks->a = stacks->b;
		stacks->b = tmp;
	}
	else
	{
		tmp = stacks->b->next;
		stacks->a = stacks->b;
		stacks->a->next = NULL;
		stacks->b = tmp;
	}
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}

void	push_b(t_stacks *stacks)
{
	t_list	*tmp;

	if (!stacks || !stacks->a)
		return;
	if (stacks->b)
	{
		tmp = stacks->a->next;
		stacks->a->next = stacks->b;
		stacks->b = stacks->a;
		stacks->a = tmp;
	}
	else
	{
		tmp = stacks->a->next;
		stacks->b = stacks->a;
		stacks->b->next = NULL;
		stacks->a = tmp;
	}
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}