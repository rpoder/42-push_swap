/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:37:36 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/05/31 18:28:01 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stacks *stacks)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = stacks->a;
	tmp_b = stacks->b;
	printf("A		B\n");
	printf("%p	%p\n", stacks->a, stacks->b);
	while (tmp_a || tmp_b)
	{
		if (tmp_a)
		{
			printf("%d    ", ((t_info *)tmp_a->content)->number);
			printf("%d", ((t_info *)tmp_a->content)->index);
			tmp_a = tmp_a->next;
		}
		printf("		");
		if (tmp_b)
		{
			printf("%d    ", ((t_info *)tmp_b->content)->number);
			printf("%d", ((t_info *)tmp_b->content)->index);
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
				stack, ((t_info *)stack->content)->number,
				((t_info *)stack->content)->index, stack->next);
			stack = stack->next;
		}
	}
	else
	{
		printf("The stack you tried to print is NULL\n");
	}
	printf("\n");
}

void	print_size(t_stacks *stacks)
{
	if (!stacks)
	{
		printf("Stacks does not exist\n");
		return ;
	}
	printf("STACKS SIZES\n");
	printf("stacks->size_a = %d\n", stacks->size_a);
	printf("stacks->size_b = %d\n\n", stacks->size_b);
}

void	print_op(t_op *op)
{
	if (!op)
	{
		printf("The OP you are trying to print does not exist.\n");
		return ;
	}
	printf("OP\n");
	printf("op->ra = %d\n", op->ra);
	printf("op->rb = %d\n", op->rb);
	printf("op->rr = %d\n", op->rr);
	printf("op->rra = %d\n", op->rra);
	printf("op->rrb = %d\n", op->rrb);
	printf("op->rrr = %d\n", op->rrr);
}
