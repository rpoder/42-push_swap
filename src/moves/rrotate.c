/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:04:39 by rpoder            #+#    #+#             */
/*   Updated: 2022/05/29 21:15:18 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_a(t_stacks *stacks)
{
	t_list	*tmp;
	t_list	*last;

	if (!stacks || !stacks->a || !stacks->a->next)
		return ;
	if (!stacks->a->next->next)
		swap_b(stacks);
	tmp = ft_lstbeflast(stacks->a);
	last = ft_lstlast(stacks->a);
	last->next = stacks->a;
	stacks->a = last;
	tmp->next = NULL;
}

void	rrotate_b(t_stacks *stacks)
{
	t_list	*tmp;
	t_list	*last;

	if (!stacks || !stacks->b || !stacks->b->next)
		return ;
	if (!stacks->b->next->next)
		swap_b(stacks);
	tmp = ft_lstbeflast(stacks->b);
	last = ft_lstlast(stacks->b);
	last->next = stacks->b;
	stacks->b = last;
	tmp->next = NULL;
}