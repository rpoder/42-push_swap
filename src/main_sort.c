/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:17:45 by rpoder            #+#    #+#             */
/*   Updated: 2022/05/31 18:10:16 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_best_case(t_stacks *stacks, int pos_a, int pos_b)
{
	int	minimum_moves;
	int	ret;

	ret = 0;
	minimum_moves = INT_MAX;
	if (a_up_b_down(stacks, pos_a, pos_b) < minimum_moves)
	{
		minimum_moves = a_up_b_down(stacks, pos_a, pos_b);
		ret = 1;
	}
	if (a_up_b_up(stacks, pos_a, pos_b) < minimum_moves)
	{
		minimum_moves = a_up_b_up(stacks, pos_a, pos_b);
		ret = 2;
	}
	if (a_down_b_up(stacks, pos_a, pos_b) < minimum_moves)
	{
		minimum_moves = a_down_b_up(stacks, pos_a, pos_b);
		ret = 3;
	}
	if (a_down_b_down(stacks, pos_a, pos_b) < minimum_moves)
		ret = 4;
	return (ret);
}

int	get_number_moves(int cas, t_stacks *stacks, int pos_a, int pos_b)
{
	int	ret;

	ret = 0;
	if (cas == 1)
		ret = a_up_b_down(stacks, pos_a, pos_b);
	else if (cas == 2)
		ret = a_up_b_up(stacks, pos_a, pos_b);
	else if (cas == 3)
		ret = a_down_b_up(stacks, pos_a, pos_b);
	else if (cas == 4)
		ret = a_down_b_down(stacks, pos_a, pos_b);
	return (ret);
}

int	get_closest_pos(t_stacks *stacks, int index_b)
{
	t_list	*tmp_a;
	int		index_a;
	int		closest;
	int		ret;

	ret = 0;
	index_a = 0;
	closest = INT_MAX;
	tmp_a = stacks->a;
	while (tmp_a)
	{
		if (((t_info *)tmp_a->content)->index > index_b)
		{
			if (((t_info *)tmp_a->content)->index < closest)
			{
				closest = ((t_info *)tmp_a->content)->index;
				ret = index_a;
			}
		}
		index_a++;
		tmp_a = tmp_a->next;
	}
	return (ret);
}

t_op	*generate_op(t_stacks *stacks, int cas, int pos_a, int pos_b)
{
	t_op	*op;

	op = set_t_op();
	if (!op)
		return (NULL);
	if (cas == 1)
		apply_a_up_b_down(stacks, op, pos_a, pos_b);
	else if (cas == 2)
		apply_a_up_b_up(stacks, op, pos_a, pos_b);
	else if (cas == 3)
		apply_a_down_b_up(stacks, op, pos_a, pos_b);
	else if (cas == 4)
		apply_a_down_b_down(stacks, op, pos_a, pos_b);
	return (op);
}

int	find_best_option(t_stacks *stacks, int b_nb_of_moves, t_best_case *b_case)
{
	t_list	*tmp_b;
	int		number_of_moves;
	int		pos_b;
	int		pos_a;
	int		cas;

	pos_b = 0;
	tmp_b = stacks->b;
	while (pos_b < stacks->size_b)
	{
		pos_a = get_closest_pos(stacks, ((t_info *)tmp_b->content)->index);
		cas = get_best_case(stacks, pos_a, pos_b);
		number_of_moves = get_number_moves(cas, stacks, pos_a, pos_b);
		if (number_of_moves < b_nb_of_moves)
		{
			b_case->cas = cas;
			b_case->pos_a = pos_a;
			b_case->pos_b = pos_b;
			b_nb_of_moves = number_of_moves;
		}
		pos_b++;
		tmp_b = tmp_b->next;
	}
	return (number_of_moves);
}

int	main_sort(t_stacks *stacks)
{
	t_op		*op;
	int			b_number_of_moves;
	t_best_case	*b_case;

	b_case = set_t_best_case();
	if (!b_case)
		return (0);
	while (stacks->b)
	{
		stacks->size_a = get_stack_size(stacks->a);
		stacks->size_b = get_stack_size(stacks->b);
		b_number_of_moves = INT_MAX;
		b_number_of_moves = find_best_option(stacks, b_number_of_moves, b_case);
		op = generate_op(stacks, b_case->cas, b_case->pos_a, b_case->pos_b);
		if (!op)
			return (0);
		execute_moves(stacks, op);
		free (op);
	}
	free (b_case);
	return (1);
}
