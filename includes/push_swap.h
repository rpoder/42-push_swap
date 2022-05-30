/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:35:55 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/05/30 18:24:12 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# define INT_MIN -2147483648
# define INT_MAX 2147483647

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

typedef struct s_op
{
	int	pos_a;
	int	pos_b;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	sum;
}	t_op;

// Libft Addons
t_list		*ft_lstbeflast(t_list *lst);

// Setters
t_stacks	*set_stacks(void);
t_list		*set_t_list(int	number);
t_op		*set_t_op(void);

// Getters
int			get_stack_size(t_list *stack);

// Reinitialisations
void		reinit_op(t_op *op);

// Prints
void		print_stacks(t_stacks *stacks);
void		print_lst(t_list *stack);
void		print_op(t_op *op);
void		print_pos(t_op *op);
void		print_size(t_stacks *stacks);

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
int			pre_sort(t_stacks *stacks);
void		indexing_a(t_list *list);
void		push_all_to_b(t_stacks *stacks);

// Main-sort
int			main_sort(t_stacks *stacks);
int			pos_of_next_greater_in_a(t_stacks *stacks, int value);

// Calculate rotates
int			a_up_b_down(t_stacks *stacks, t_op *op);
int			a_up_b_up(t_stacks *stacks, t_op *op);
int			a_down_b_up(t_stacks *stacks, t_op *op);
int			a_down_b_down(t_stacks *stacks, t_op *op);


#endif
