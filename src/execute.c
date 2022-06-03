/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:00:10 by rpoder            #+#    #+#             */
/*   Updated: 2022/06/03 15:08:04 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_moves(t_stacks *stacks, t_op *op)
{
	if (!op)
		return ;
	while (op->ra && op->rb)
	{
		rotate_both(stacks);
		op->ra--;
		op->rb--;
	}
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
	while (op->rra && op->rrb)
	{
		rrotate_both(stacks);
		op->rra--;
		op->rrb--;
	}
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
