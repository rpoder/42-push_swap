/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_rotates.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:36:58 by rpoder            #+#    #+#             */
/*   Updated: 2022/06/03 14:46:04 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_a_up_b_down(t_stacks *stacks, t_op *op, int pos_a, int pos_b)
{
	op->ra = pos_a;
	op->rrb = stacks->size_b - pos_b;
}

void	apply_a_up_b_up(t_stacks *stacks, t_op *op, int pos_a, int pos_b)
{
	(void) stacks;
	op->ra = pos_a;
	op->rb = pos_b;
}

void	apply_a_down_b_up(t_stacks *stacks, t_op *op, int pos_a, int pos_b)
{
	op->rra = stacks->size_a - pos_a;
	op->rb = pos_b;
}

void	apply_a_down_b_down(t_stacks *stacks, t_op *op, int pos_a, int pos_b)
{
	op->rra = stacks->size_a - pos_a;
	op->rrb = stacks->size_b - pos_b;
}
