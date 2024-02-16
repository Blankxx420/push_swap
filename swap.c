/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:37:13 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/16 09:50:08 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack)
{
	char *tmp;

	if (!stack || !stack->next)
		return ; 
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
}

void	sb(t_list *stack_b)
{
	swap(stack_b);
	ft_putendl_fd("sb", 1);
}

void	sa(t_list *stack_a)
{
	swap(stack_a);
	ft_putendl_fd("sa", 1);
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_putendl_fd("ss", 1);
}
