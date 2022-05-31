/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:17:45 by rpoder            #+#    #+#             */
/*   Updated: 2022/05/31 16:42:58 by rpoder           ###   ########.fr       */
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
	{
		minimum_moves = a_down_b_down(stacks, pos_a, pos_b);
		ret = 4;
	}
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

int	get_closest_position(t_stacks *stacks, int index_b)
{
	t_list	*tmp_a;
	int		index_a;
	int		closest;
	int		ret;

	ret = 0;
	index_a = 0;
	closest = INT_MAX;
	tmp_a = stacks->a;
	//printf("index_b %d\n", index_b);
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

t_op	*generate_operations(t_stacks *stacks, int cas, int pos_a, int pos_b)
{
	t_op	*op;

	op = set_t_op();
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

int	main_sort(t_stacks *stacks)
{
	t_op	*op;
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		pos_b;
	int		pos_a;
	int		best_pos_b;
	int		best_pos_a;
	int		best_case;
	int		number_of_moves;
	int		best_number_of_moves;
	int		cas;

	// op = set_t_op();
	// if (!op)
	// 	return (0);
	while (stacks->b)
	{
		pos_b = 0;
		tmp_a = stacks->a;
		tmp_b = stacks->b;

		stacks->size_a = get_stack_size(stacks->a);
		stacks->size_b = get_stack_size(stacks->b);
		best_number_of_moves = INT_MAX;

			while (pos_b < stacks->size_b)
			{
				pos_a = get_closest_position(stacks, ((t_info *)tmp_b->content)->index);
				cas = get_best_case(stacks, pos_a, pos_b);
				number_of_moves = get_number_moves(cas, stacks, pos_a, pos_b);
				if (number_of_moves < best_number_of_moves)
				{
					//printf("better\n");
					best_case = cas;
					best_pos_a = pos_a;
					best_pos_b = pos_b;
					best_number_of_moves = number_of_moves;
				}
				pos_b++;
				tmp_b = tmp_b->next;
			}
		op = generate_operations(stacks, best_case, best_pos_a, best_pos_b);
		execute_moves(stacks, op);
		free (op);
	}
	//free(op);
	return (0);
}
