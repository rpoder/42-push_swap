/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:35:29 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/05/30 11:47:33 by rpoder           ###   ########.fr       */
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

	pre_sort(stacks);
	main_sort(stacks);
	// print_stacks(stacks);
	// print_lst(stacks->a);
	// print_lst(stacks->b);

}
