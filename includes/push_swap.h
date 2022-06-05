/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 18:35:55 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/06/05 19:36:04 by ronanpoder       ###   ########.fr       */
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

typedef struct s_best_case
{
	int	cas;
	int	pos_a;
	int	pos_b;
}	t_best_case;

typedef struct s_op
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
}	t_op;

// Main
void		push_swap(char **arg);
void		sort_less_than_five(t_stacks *stacks);
void		sort_three(t_stacks *stacks);

// Checks
int			check_args(char **argv);
int			check_sign(char *arg);
int			ft_is_int(long int num);
int			check_double(t_list *stack);
int			check_is_sorted(t_list *stack);

// Libft Addons
t_list		*ft_lstbeflast(t_list *lst);
long int	ft_atol(char *s);
void		ft_free_double_tab(char **tab);

// Setters
t_stacks	*set_stacks(void);
t_list		*set_t_list(int number);
t_op		*set_t_op(void);
t_best_case	*set_t_best_case(void);

// Getters
int			get_stack_size(t_list *stack);

// Prints
void		print_stacks(t_stacks *stacks);
void		print_lst(t_list *stack);
void		print_op(t_op *op);
void		print_pos(t_op *op);
void		print_size(t_stacks *stacks);

// Fillers
t_list		*fill_stack_a(char **argv);

// Moves
void		push_a(t_stacks *stacks);
void		push_b(t_stacks *stacks);
void		rotate_a(t_stacks *stacks, int print);
void		rotate_b(t_stacks *stacks, int print);
void		rotate_both(t_stacks *stacks);
void		rrotate_a(t_stacks *stacks, int print);
void		rrotate_b(t_stacks *stacks, int print);
void		rrotate_both(t_stacks *stacks);
void		swap_a(t_stacks *stacks);
void		swap_b(t_stacks *stacks);

// Pre-sort
int			pre_sort(t_stacks *stacks);
void		indexing_a(t_list *list);
void		push_all_to_b(t_stacks *stacks);

// Mini Presort
void		mini_presort(t_stacks *stacks);

// Main-sort
int			main_sort(t_stacks *stacks);
int			get_best_case(t_stacks *stacks, int pos_a, int pos_b);
int			get_closest_pos(t_stacks *stacks, int index_b);
int			get_number_moves(int cas, t_stacks *stacks, int pos_a, int pos_b);
t_op		*generate_op(t_stacks *stacks, int cas, int pos_a, int pos_b);
int			find_best_option(t_stacks *stacks, int b_nb_of_moves,
				t_best_case *b_case);

// Execute
void		execute_moves(t_stacks *stacks, t_op *op);

// Calculate rotates
int			a_up_b_down(t_stacks *stacks, int pos_a, int pos_b);
int			a_up_b_up(t_stacks *stacks, int pos_a, int pos_b);
int			a_down_b_up(t_stacks *stacks, int pos_a, int pos_b);
int			a_down_b_down(t_stacks *stacks, int pos_a, int pos_b);

// Apply rotates
void		apply_a_up_b_down(t_stacks *stacks, t_op *op, int pos_a, int pos_b);
void		apply_a_up_b_up(t_stacks *stacks, t_op *op, int pos_a, int pos_b);
void		apply_a_down_b_up(t_stacks *stacks, t_op *op, int pos_a, int pos_b);
void		apply_a_down_b_down(t_stacks *stacks, t_op *op, int pos_a,
				int pos_b);

// Last Sort
void		last_sort(t_stacks *stacks);

// Frees
void		free_stacks(t_stacks *stacks);
void		del_t_info(void *to_delete);

#endif
