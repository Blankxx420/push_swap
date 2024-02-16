/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:38:18 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/16 09:39:06 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (!(*stack))
		return ;
	tmp = (*stack);
	last = ft_lstlast(tmp);
	(*stack) = (*stack)->next;
	last->next = tmp;
	last->next->next = NULL;
}

void	ra(t_list **stack)
{
	rotate(stack);
	ft_putendl_fd("ra", 1);
}

void	rb(t_list **stack)
{
	rotate(stack);
	ft_putendl_fd("rb", 1);
}

void	rr(t_list *stack_a, t_list *stack_b)
{
	ra(&stack_a);
	rb(&stack_b);
	ft_putendl_fd("rr", 1);
}