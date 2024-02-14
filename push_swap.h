/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:06:15 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/14 14:37:15 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
#include <stdio.h> //norm

typedef struct s_stack
{
	t_list	*stack_a;
	t_list	*stack_b;
}				t_stack;

void			init_stack(t_stack *stack, int argc, char **argv);
char 			**split_argv(char **argv, int argc);
int 			check_double_int(t_stack *stack, long long int *num);
int				check_argv(char **args);
int 			check_len_nbr(char *arg);

// move possible of stack
void			sa(t_list *stack_a);
void			sb(t_list *stack_b);
void			ss(t_list *stack_a, t_list *stack_b);
void			pa(t_list **stack_a, t_list **stack_b);
void			pb(t_list **stack_a, t_list **stack_b);
void			ra(t_list **stack_a);
void			rb(t_list **stack_a);
void			rr(t_list *stack_a, t_list *stack_b);
void			rra(t_list **stack_a);

void			resolve_2_and_3(t_list **stack_a);
void			resolve_4_and_5(t_list **stack_a, t_list **stack_b);
long long int	get_little_min(t_list *stack_a);
long long int 	*init_tab(t_list *stack_a);
long long int 	*sort_tab(long long int *tab, int size);
long long int	calculate_median(int size, long long int *tab);
void			sort_stack(t_list **stack_a, t_list **stack_b, long long *tab);
#endif
