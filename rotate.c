/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:38:18 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/19 10:22:33 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (ft_lstsize(*stack) < 2)
		return ;
	tmp = (*stack);
	last = ft_lstlast(tmp);
	(*stack) = tmp->next;
	tmp->next = NULL;
	last->next = tmp;
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