/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:00:10 by rpoder            #+#    #+#             */
/*   Updated: 2022/05/30 23:01:11 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_moves(t_stacks *stacks, t_op *op)
{
	if (!op)
		return ;
	while (op->ra)
	{
		rotate_a(stacks);
		op->ra--;
	}
	while (op->rb)
	{
		rotate_b(stacks);
		op->rb--;
	}
	while (op->rra)
	{
		rrotate_a(stacks);
		op->rra--;
	}
	while (op->rrb)
	{
		rrotate_b(stacks);
		op->rrb--;
	}
	push_a(stacks);
}
