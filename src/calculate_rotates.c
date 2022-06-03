/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rotates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:36:58 by rpoder            #+#    #+#             */
/*   Updated: 2022/06/03 14:49:25 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	a_up_b_down(t_stacks *stacks, int pos_a, int pos_b)
{
	int	ra;
	int	rrb;

	ra = pos_a;
	rrb = stacks->size_b - pos_b;
	return (ra + rrb);
}

int	a_up_b_up(t_stacks *stacks, int pos_a, int pos_b)
{
	int	ra;
	int	rb;

	(void) stacks;
	ra = pos_a;
	rb = pos_b;
	return (ra + rb);
}

int	a_down_b_up(t_stacks *stacks, int pos_a, int pos_b)
{
	int	rra;
	int	rb;

	rra = stacks->size_a - pos_a;
	rb = pos_b;
	return (rra + rb);
}

int	a_down_b_down(t_stacks *stacks, int pos_a, int pos_b)
{
	int	rra;
	int	rrb;

	rra = stacks->size_a - pos_a;
	rrb = stacks->size_b - pos_b;
	return (rra + rrb);
}
