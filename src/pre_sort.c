/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 21:26:01 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/05/29 22:03:38 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_to_b(t_stacks *stacks)
{
	int	max;
	int	median;

	max = get_stack_size(stacks->a);
	median = max / 2;
	while (stacks->a->next)
	{
		if (((t_info *)stacks->a->content)->index != max)
		{
			if (((t_info *)stacks->a->content)->index > median)
				push_b(stacks);
			else
			{
				push_b(stacks);
				rotate_b(stacks);
			}
		}
		else
		{
			rotate_a(stacks);
		}
	}
}

void	indexing_a(t_list *list)
{
	int		greater_than;
	t_list	*first;
	t_list	*tmp;

	first = list;
	while (list)
	{
		tmp = first;
		greater_than = 0;
		while (tmp)
		{
			if (((t_info *)list->content)->number > ((t_info *)tmp->content)->number)
				greater_than ++;
			tmp = tmp->next;
		}
		((t_info *)list->content)->index = greater_than;
		list = list->next;
	}
	list = first;
}