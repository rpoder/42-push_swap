/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:35:29 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/06/05 19:28:46 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char		**arg;
	int			is_malloced;

	is_malloced = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		arg = ft_split(argv[1], ' ');
		is_malloced = 1;
	}
	else
		arg = argv + 1;
	if (!arg)
		return (0);
	if (!check_args(arg))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	push_swap(arg);
	if (is_malloced == 1)
		ft_free_double_tab(arg);
}

void	push_swap(char **arg)
{
	int			ret;
	t_stacks	*stacks;

	stacks = set_stacks();
	stacks->a = fill_stack_a(arg);
	if (check_double(stacks->a) || check_is_sorted(stacks->a))
		return ;
	if (ft_lstsize(stacks->a) <= 5)
		sort_less_than_five(stacks);
	else
	{
		pre_sort(stacks);
		ret = main_sort(stacks);
		if (!ret)
		{
			free_stacks(stacks);
			return ;
		}
		last_sort(stacks);
	}
	free_stacks(stacks);
}

void	sort_three(t_stacks	*stacks)
{
	t_list	*stack;
	int		a;
	int		b;
	int		c;

	stack = stacks->a;
	a = ((t_info *)stack->content)->index;
	b = ((t_info *)stack->next->content)->index;
	c = ((t_info *)stack->next->next->content)->index;
	if (a < c && c < b)
	{
		rrotate_a(stacks, 1);
		swap_a(stacks);
	}
    if (b < c && c < a)
		rotate_a(stacks, 1);
    if (b < a && a < c)
		swap_a(stacks);
    if (c < a && a < b)
		rrotate_a(stacks, 1);
    if (c < b && b < a)
	{
		swap_a(stacks);
		rrotate_a(stacks, 1);
	}
}

void	sort_less_than_five(t_stacks *stacks)
{
	int	ret;

	stacks->size_a = ft_lstsize(stacks->a);
	indexing_a(stacks->a);
	if (stacks->size_a == 2)
		swap_a(stacks);
	else if (stacks->size_a == 3)
	{
		sort_three(stacks);
		return ;
	}
	else
	{
		mini_presort(stacks);
		sort_three(stacks);
		ret = main_sort(stacks);
		if (!ret)
		{
			free_stacks(stacks);
			return ;
		}
		last_sort(stacks);
	}
}
