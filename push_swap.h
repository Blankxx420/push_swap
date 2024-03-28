/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:06:15 by brguicho          #+#    #+#             */
/*   Updated: 2024/03/28 22:41:22 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h> //norm

typedef struct s_stack
{
	t_list	*stack_a;
	t_list	*stack_b;
}				t_stack;

typedef struct s_best
{
	int	nb_a;
	int	type_a;
	int	type_b;
	int	nb_b;
	int	nb_total;
	int	size_a;
	int	size_b;
}				t_best;

void			init_stack(t_stack *stack, int argc, char **argv);
void			put_in_stack(t_stack *stack, char *arg, char **args);
char			**split_argv(char **argv, int argc);
int				check_double_int(t_stack *stack, long long int *num);
int				check_argv(char **args);
int				check_len_nbr(char *arg);

// move possible of stack
void			swap(t_list *stack);
void			sa(t_list *stack_a);
void			sb(t_list *stack_b);
void			ss(t_list *stack_a, t_list *stack_b);
void			pa(t_list **stack_a, t_list **stack_b);
void			pb(t_list **stack_a, t_list **stack_b);
void			rotate(t_list **stack);
void			ra(t_list **stack);
void			rb(t_list **stack);
void			rr(t_list **stack_a, t_list **stack_b);
void			rra(t_list **stack);
void			rrb(t_list **stack);
void			rrr(t_list **stack_a, t_list **stack_b);

void			resolve_2_and_3(t_list **stack_a);
void			resolve_4_and_5(t_list **stack_a, t_list **stack_b);
long long int	get_little_min(t_list *stack_a);
long long int	*init_tab(t_list *stack_a);
long long int	*sort_tab(long long int *tab, int size);
long long int	calculate_median(int size, long long int *tab);
t_stack			presort_stack(t_stack data, long long *tab);
int				get_position(long long *tab, void *content, int tablen);
void			check_position(t_list **stack_a,
					t_list **stack_b, int position);
long long		get_min(t_list *stack);
long long		get_target(t_list *stack_a, t_list *stack_b, long long min);
int				calculate_position(t_list *stack, long long content);
void			calculate_best_move(t_stack data);
long long int	get_max(t_list *stack_a);
long long int	get_nearest_max(t_list *stack_a, void *content);
int				get_total(t_best *current);
void			play_move(t_best best, t_stack *data);
void			get_type(int i, int j, t_best *current);
void			ft_last_move(t_list *stack_a);
int				big_sort(t_stack *data);
int				push_swap(t_stack *data);

#endif
