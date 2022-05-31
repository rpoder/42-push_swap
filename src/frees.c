/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:42:22 by rpoder            #+#    #+#             */
/*   Updated: 2022/05/31 16:47:47 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_stacks *stacks)
{
	ft_lstclear(&stacks->a, &del_t_info);
	ft_lstclear(&stacks->b, &del_t_info);
	free(stacks);
}

void	del_t_info(void *to_delete)
{
	free((t_info *)to_delete);
}
