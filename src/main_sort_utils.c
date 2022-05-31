/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:42:51 by rpoder            #+#    #+#             */
/*   Updated: 2022/05/31 18:43:43 by rpoder           ###   ########.fr       */
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
