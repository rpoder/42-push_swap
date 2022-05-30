/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rotates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:36:58 by rpoder            #+#    #+#             */
/*   Updated: 2022/05/30 16:46:50 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	moves_sum(t_op *op)
{
	int	sum;

	sum = 0;
	sum += op->ra;
	sum += op->rb;
	sum += op->rr;
	sum += op->rra;
	sum += op->rrb;
	sum += op->rrr;
	return (sum);
}

int	a_up_b_down(t_stacks *stacks, t_op *op)
{
	reinit_op(op);
	op->ra = op->pos_a;
	op->rrb = stacks->size_b - op->pos_b;
	op->sum = moves_sum(op);
	return (op->sum);
}

int	a_up_b_up(t_stacks *stacks, t_op *op)
{
	reinit_op(op);
	op->ra = op->pos_a;
	op->rb = op->pos_b;
	op->sum = moves_sum(op);
	return (op->sum);
}

int	a_down_b_up(t_stacks *stacks, t_op *op)
{
	reinit_op(op);
	op->rra = stacks->size_a - op->pos_a;
	op->rb = op->pos_b;
	op->sum = moves_sum(op);
	return (op->sum);
}

int	a_down_b_down(t_stacks *stacks, t_op *op)
{
	reinit_op(op);
	op->rra = stacks->size_a - op->pos_a;
	op->rrb = stacks->size_b - op->pos_b;
	op->sum = moves_sum(op);
	return (op->sum);
}
