/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_presort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 19:16:08 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/06/05 19:29:27 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_b(t_stacks *stacks)
{
	int	max;

	max = get_stack_size(stacks->a) - 1;
	while (stacks->a->next->next->next)
	{
		if (((t_info *)stacks->a->content)->index != max)
		{
			push_b(stacks);
		}
		else
		{
			rotate_a(stacks, 1);
		}
	}
}

void	mini_presort(t_stacks *stacks)
{
	push_to_b(stacks);
}
