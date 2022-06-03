/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 14:43:01 by rpoder            #+#    #+#             */
/*   Updated: 2022/06/03 15:04:57 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	last_sort(t_stacks *stacks)
{
	int		pos_a;
	t_list	*tmp_a;
	int		size_a;

	tmp_a = stacks->a;
	pos_a = 0;
	while (tmp_a)
	{
		if (((t_info *)tmp_a->content)->index == 0)
			break ;
		tmp_a = tmp_a->next;
		pos_a++;
	}
	size_a = get_stack_size(stacks->a);
	if ((size_a / 2) > pos_a)
	{
		while (((t_info *)stacks->a->content)->index != 0)
			rotate_a(stacks, 1);
	}
	else
	{
		while (((t_info *)stacks->a->content)->index != 0)
			rrotate_a(stacks, 1);
	}
}
