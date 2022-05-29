/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 19:05:06 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/05/29 19:55:26 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*fill_stack_a(t_stacks	*stacks, char **argv)
{
	t_list	*a;
	t_list	*new;
	int		i;

	i = 1;
	a = set_t_list(ft_atoi(argv[i]));
	i++;
	while (argv[i])
	{
		new = set_t_list(ft_atoi(argv[i]));
		if (!new)
			return (NULL);
		ft_lstadd_back(&a, new);
		i++;
	}
	return (a);
}