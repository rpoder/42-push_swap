/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:04:39 by rpoder            #+#    #+#             */
/*   Updated: 2022/06/03 15:06:01 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_a(t_stacks *stacks, int print)
{
	t_list	*tmp;
	t_list	*last;

	if (!stacks || !stacks->a || !stacks->a->next)
		return ;
	if (!stacks->a->next->next)
	{
		swap_a(stacks);
		return ;
	}
	tmp = ft_lstbeflast(stacks->a);
	last = ft_lstlast(stacks->a);
	last->next = stacks->a;
	stacks->a = last;
	tmp->next = NULL;
	if (print == 1)
		ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void	rrotate_b(t_stacks *stacks, int print)
{
	t_list	*tmp;
	t_list	*last;

	if (!stacks || !stacks->b || !stacks->b->next)
		return ;
	if (!stacks->b->next->next)
	{
		swap_b(stacks);
		return ;
	}
	tmp = ft_lstbeflast(stacks->b);
	last = ft_lstlast(stacks->b);
	last->next = stacks->b;
	stacks->b = last;
	tmp->next = NULL;
	if (print == 1)
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

void	rrotate_both(t_stacks *stacks)
{
	rrotate_a(stacks, 0);
	rrotate_b(stacks, 0);
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
