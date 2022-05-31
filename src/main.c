/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:35:29 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/05/31 16:30:25 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	int			ret;

	(void) argv;
	if (argc < 2)
		return (0);
	stacks = set_stacks();
	stacks->a = fill_stack_a(stacks, argv);
	pre_sort(stacks);
	ret = main_sort(stacks);
	if (!ret)
	{
		free_stacks(stacks);
		free(stacks);
		return (0);
	}
	last_sort(stacks);
	free_stacks(stacks);
	free(stacks);
	//print_stacks(stacks);
	}
