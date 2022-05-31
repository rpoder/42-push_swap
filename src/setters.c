/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:44:05 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/05/31 18:20:46 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*set_stacks(void)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->size_a = 0;
	stacks->size_b = 0;
	return (stacks);
}

t_list	*set_t_list(int number)
{
	t_list	*new;
	t_info	*new_tinfo;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new_tinfo = (t_info *)malloc(sizeof(t_info));
	if (!new_tinfo)
		return (NULL);
	new_tinfo->number = number;
	new_tinfo->index = 0;
	new->content = new_tinfo;
	new->next = NULL;
	return (new);
}

t_op	*set_t_op(void)
{
	t_op	*op;

	op = (t_op *)malloc(sizeof(t_op));
	if (!op)
		return (NULL);
	op->ra = 0;
	op->rb = 0;
	op->rr = 0;
	op->rra = 0;
	op->rrb = 0;
	op->rrr = 0;
	return (op);
}

t_best_case	*set_t_best_case(void)
{
	t_best_case	*b_case;

	b_case = malloc(sizeof(t_best_case));
	if (!b_case)
		return (NULL);
	b_case->cas = 0;
	b_case->pos_a = 0;
	b_case->pos_b = 0;
	return (b_case);
}
