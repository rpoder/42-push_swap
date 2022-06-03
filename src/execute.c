/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:00:10 by rpoder            #+#    #+#             */
/*   Updated: 2022/06/03 16:53:13 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_rr(t_stacks *stacks, t_op *op)
{
	while (op->ra && op->rb)
	{
		rotate_both(stacks);
		op->ra--;
		op->rb--;
	}
}

static void	execute_rrr(t_stacks *stacks, t_op *op)
{
	while (op->rra && op->rrb)
	{
		rrotate_both(stacks);
		op->rra--;
		op->rrb--;
	}
}

void	execute_moves(t_stacks *stacks, t_op *op)
{
	if (!op)
		return ;
	execute_rr(stacks, op);
	while (op->ra)
	{
		rotate_a(stacks, 1);
		op->ra--;
	}
	while (op->rb)
	{
		rotate_b(stacks, 1);
		op->rb--;
	}
	execute_rrr(stacks, op);
	while (op->rra)
	{
		rrotate_a(stacks, 1);
		op->rra--;
	}
	while (op->rrb)
	{
		rrotate_b(stacks, 1);
		op->rrb--;
	}
	push_a(stacks);
}
