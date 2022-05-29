/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:35:55 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/05/29 22:01:21 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef _PUSH_SWAP_H_
# define _PUSH_SWAP_H_

#include "libft.h"
#include <stdio.h>

typedef struct s_info
{
	int	number;
	int	index;
}	t_info;

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
	int		size_a;
	int		size_b;
}	t_stacks;

// Libft Addons
t_list	*ft_lstbeflast(t_list *lst);

// Setters
t_stacks	*set_stacks(void);
t_list		*set_t_list(int	number);

// Getters
int			get_stack_size(t_list *stack);

// Prints
void 		print_stacks(t_stacks *stacks);
void		print_lst(t_list *stack);

// Fillers
t_list		*fill_stack_a(t_stacks	*stacks, char **argv);

// Moves
void		push_a(t_stacks *stacks);
void		push_b(t_stacks *stacks);
void		rotate_a(t_stacks *stacks);
void		rotate_b(t_stacks *stacks);
void		rrotate_a(t_stacks *stacks);
void		rrotate_b(t_stacks *stacks);
void		swap_a(t_stacks *stacks);
void		swap_b(t_stacks *stacks);

// Pre-sort
void	indexing_a(t_list *list);
void	push_all_to_b(t_stacks *stacks);


#endif