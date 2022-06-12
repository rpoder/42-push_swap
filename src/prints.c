/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:37:36 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/06/12 20:04:56 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stacks *stacks)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = stacks->a;
	tmp_b = stacks->b;
	ft_printf("A		B\n");
	ft_printf("%p	%p\n", stacks->a, stacks->b);
	while (tmp_a || tmp_b)
	{
		if (tmp_a)
		{
			ft_printf("%d    ", ((t_info *)tmp_a->content)->number);
			ft_printf("%d", ((t_info *)tmp_a->content)->index);
			tmp_a = tmp_a->next;
		}
		ft_printf("		");
		if (tmp_b)
		{
			ft_printf("%d    ", ((t_info *)tmp_b->content)->number);
			ft_printf("%d", ((t_info *)tmp_b->content)->index);
			tmp_b = tmp_b->next;
		}
		ft_printf("\n");
	}
	ft_printf("\n");
}

void	print_lst(t_list *stack)
{
	ft_printf("STACK PRINT\n");
	if (stack)
	{
		while (stack)
		{
			ft_printf("-> Addr %p	Number = %d	Index = %d	Next %p\n",
				stack, ((t_info *)stack->content)->number,
				((t_info *)stack->content)->index, stack->next);
			stack = stack->next;
		}
	}
	else
	{
		ft_printf("The stack you tried to print is NULL\n");
	}
	ft_printf("\n");
}

void	print_size(t_stacks *stacks)
{
	if (!stacks)
	{
		ft_printf("Stacks does not exist\n");
		return ;
	}
	ft_printf("STACKS SIZES\n");
	ft_printf("stacks->size_a = %d\n", stacks->size_a);
	ft_printf("stacks->size_b = %d\n\n", stacks->size_b);
}

void	print_op(t_op *op)
{
	if (!op)
	{
		ft_printf("The OP you are trying to print does not exist.\n");
		return ;
	}
	ft_printf("OP\n");
	ft_printf("op->ra = %d\n", op->ra);
	ft_printf("op->rb = %d\n", op->rb);
	ft_printf("op->rra = %d\n", op->rra);
	ft_printf("op->rrb = %d\n", op->rrb);
}
