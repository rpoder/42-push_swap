/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:04:04 by rpoder            #+#    #+#             */
/*   Updated: 2022/05/31 18:40:22 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stacks *stacks)
{
	t_list	*tmp;

	if (!stacks || !stacks->a || !stacks->a->next)
		return ;
	tmp = stacks->a->next;
	stacks->a->next = tmp->next;
	tmp->next = stacks->a;
	stacks->a = tmp;
	ft_putstr_fd("sa\n", STDOUT_FILENO);
}

void	swap_b(t_stacks *stacks)
{
	t_list	*tmp;

	if (!stacks || !stacks->b || !stacks->a->next)
		return ;
	tmp = stacks->b->next;
	stacks->b->next = tmp->next;
	tmp->next = stacks->b;
	stacks->b = tmp;
	ft_putstr_fd("sb\n", STDOUT_FILENO);
}
