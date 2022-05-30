/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:17:45 by rpoder            #+#    #+#             */
/*   Updated: 2022/05/30 12:13:40 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	best_moves(t_stacks *stacks, t_op *op)
{
	int		moves;
	t_op	*tmp;

	tmp = set_t_op();
	tmp->pos_a = op->pos_a;
	tmp->pos_b = op->pos_b;
	if (!tmp)
		return (-1);
	//DEBUGS
	print_pos(tmp);
	print_size(stacks);
	if (a_up_b_down(stacks, tmp) < op->sum)
		moves = a_up_b_down(stacks, op);
	if (a_up_b_up(stacks, tmp) < op->sum)
		moves = a_up_b_up(stacks, op);
	if (a_down_b_up(stacks, tmp) < op->sum)
		moves = a_down_b_up(stacks, op);
	if (a_down_b_down(stacks, tmp) < op->sum)
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
		op->ra--;
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
}

int	main_sort(t_stacks *stacks)
{
	t_op	*op;
	t_list	*tmp_a;
	t_list	*tmp_b;

	op = set_t_op();

	tmp_a = stacks->a;
	tmp_b = stacks->b;
	tmp_b = tmp_b->next;
	print_lst(stacks->a);
	print_lst(stacks->b);
	stacks->size_a = get_stack_size(stacks->a);
	stacks->size_b = get_stack_size(stacks->b);
	op->pos_b = 1;
	op->pos_a = pos_of_next_greater_in_a(stacks, ((t_info *)tmp_b->content)->index);
	best_moves(stacks, op);
	print_op(op);

	//printf("pos next greater = %d\n", pos_of_next_greater_in_a(stacks, 10));
	//print_op(op);
	return (0);
}

int	pos_of_next_greater_in_a(t_stacks *stacks, int value)
{
	t_list	*tmp;
	int		pos_a;
	int		found;

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
