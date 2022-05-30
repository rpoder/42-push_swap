/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:17:45 by rpoder            #+#    #+#             */
/*   Updated: 2022/05/30 20:56:39 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	best_moves(t_stacks *stacks, t_op *op)
{
	int		moves;
	t_op	*tmp;

	moves = INT_MAX;
	tmp = set_t_op();
	tmp->pos_a = op->pos_a;
	tmp->pos_b = op->pos_b;
	if (!tmp)
		return (-1);
	if (a_up_b_down(stacks, tmp) < moves)
		moves = a_up_b_down(stacks, op);
	if (a_up_b_up(stacks, tmp) < moves)
		moves = a_up_b_up(stacks, op);
	if (a_down_b_up(stacks, tmp) < moves)
		moves = a_down_b_up(stacks, op);
	if (a_down_b_down(stacks, tmp) < moves)
		moves = a_down_b_down(stacks, op);
	free(tmp);
	return (moves);
}

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
	//print_stacks(stacks);
	push_a(stacks);
}

int	main_sort(t_stacks *stacks)
{
	t_op	*op;
	t_op	*tmp_op;
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		move;

	op = set_t_op();
	tmp_op = set_t_op();
	tmp_a = stacks->a;
	tmp_b = stacks->b;
	while (stacks->b)
	{
		move = 0;
		tmp_b = stacks->b;
		op->pos_b = 0;
		reinit_op(op);
		stacks->size_a = get_stack_size(stacks->a);
		stacks->size_b = get_stack_size(stacks->b);
		while (op->pos_b < stacks->size_b)
		{
			op->pos_a = pos_of_next_greater_in_a(stacks, ((t_info *)tmp_b->content)->index);
			if (op->pos_a != -1)
			{
				if (best_moves(stacks, tmp_op) <= op->sum)
				{
					move = 1;
					best_moves(stacks, op);
				}
			}
			tmp_b = tmp_b->next;
			op->pos_b++;
		}
		if (move)
		{
			print_stacks(stacks);
			print_op(op);
			execute_moves(stacks, op);
		}
	}
	return (0);
}

int	pos_of_next_greater_in_a(t_stacks *stacks, int value)
{
	t_list	*tmp;
	int		pos_a;
	int		found;
	int		tmp_pos;
	int		min_greater_value;

	found = 0;
	pos_a = 0;
	tmp = stacks->a;
	while (tmp)
	{
		if (((t_info *)tmp->content)->index == value + 1)
		{
			found = 1;
			break ;
		}
		pos_a++;
		tmp = tmp->next;
	}
	if (found)
		return (pos_a);
	else
		return (-1);
}
