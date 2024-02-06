/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:06:15 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/06 13:35:41 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	t_list	*stack_a;
	t_list	*stack_b;
}				t_stack;

void	init_stack(t_stack *stack, int argc, char **argv);
char 	**split_argv(char **argv, int argc);
#endif
