/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:35:29 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/05/29 22:03:19 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	(void) argv;
	if (argc < 2)
		return (1);
	stacks = set_stacks();
	stacks->a = fill_stack_a(stacks, argv);
		indexing_a(stacks->a);

	push_all_to_b(stacks);
	print_stacks(stacks);
	print_lst(stacks->b);
}