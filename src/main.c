/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:35:29 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/06/03 16:47:11 by rpoder           ###   ########.fr       */
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
	{
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	pre_sort(stacks);
	ret = main_sort(stacks);
	if (!ret)
	{
		free_stacks(stacks);
		return ;
	}
	last_sort(stacks);
	free_stacks(stacks);
}
