/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:37:36 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/05/29 21:06:47 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stacks(t_stacks *stacks)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = stacks->a;
	tmp_b = stacks->b;
	printf("------------------------\n");
	printf("A		B\n");
	printf("%p	%p\n", stacks->a, stacks->b);
	printf("------------------------\n");
	while (tmp_a || tmp_b)
	{
		if (tmp_a)
		{
			printf("%d", ((t_info *)tmp_a->content)->number);
			tmp_a = tmp_a->next;
		}
		printf("		");
		if (tmp_b)
		{
			printf("%d", ((t_info *)tmp_b->content)->number);
			tmp_b = tmp_b->next;
		}
		printf("\n");
	}
	printf("\n");
}

void	print_lst(t_list *stack)
{

	printf("STACK PRINT\n");
	if (stack)
	{
		while (stack)
		{
			printf("-> Addr %p	Number = %d	Index = %d	Next %p\n",
				stack, ((t_info *)stack->content)->number, ((t_info *)stack->content)->index, stack->next);
			stack = stack->next;
		}
	}
	else
	{
		printf("The stack you tried to print is NULL\n");
	}
	printf("\n");
}