/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:04:04 by rpoder            #+#    #+#             */
/*   Updated: 2022/05/29 21:16:35 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stacks *stacks)
{
	t_list	*tmp;

	if (!stacks || !stacks->a || !stacks->a->next)
		return;
	tmp = stacks->a->next;
	stacks->a->next = tmp->next;
	tmp->next = stacks->a;
	stacks->a = tmp;
}

void	swap_b(t_stacks *stacks)
{
	t_list	*tmp;

	if (!stacks || !stacks->b || !stacks->a->next)
		return;
	tmp = stacks->b->next;
	stacks->b->next = tmp->next;
	tmp->next = stacks->b;
	stacks->b = tmp;
}