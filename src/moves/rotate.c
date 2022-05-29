/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:04:39 by rpoder            #+#    #+#             */
/*   Updated: 2022/05/29 21:11:41 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stacks *stacks)
{
	t_list	*tmp;
	t_list	*first;

	if (!stacks || !stacks->a || !stacks->a->next)
		return ;
	first = stacks->a->next;
	tmp = stacks->a;
	tmp = ft_lstlast(tmp);
	tmp->next = stacks->a;
	tmp->next->next = NULL;
	stacks->a = first;
}

void	rotate_b(t_stacks *stacks)
{
	t_list	*tmp;
	t_list	*first;

	if (!stacks || !stacks->b || !stacks->b->next)
		return ;
	first = stacks->b->next;
	tmp = stacks->b;
	tmp = ft_lstlast(tmp);
	tmp->next = stacks->b;
	tmp->next->next = NULL;
	stacks->b = first;
}