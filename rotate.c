/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:38:18 by brguicho          #+#    #+#             */
/*   Updated: 2024/03/28 22:29:56 by brguicho         ###   ########.fr       */
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
}

void	rb(t_list **stack)
{
	rotate(stack);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_putendl_fd("rr", 1);
}
