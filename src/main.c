/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:35:29 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/05/31 18:24:36 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	int			ret;

	if (argc < 2)
		return (0);
	stacks = set_stacks();
	stacks->a = fill_stack_a(argv);
	pre_sort(stacks);
	ret = main_sort(stacks);
	if (!ret)
	{
		free_stacks(stacks);
		return (0);
	}
	last_sort(stacks);
	free_stacks(stacks);
	}
