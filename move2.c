/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:16:10 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/10 15:04:40 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*last;

	if (!(*stack_a))
		return ;
	tmp = (*stack_a);
	last = ft_lstlast(tmp);
	(*stack_a) = (*stack_a)->next;
	last->next = tmp;
	last->next->next = NULL;
}

void	rb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*last;

	if (!(*stack_b))
		return ;
	tmp = (*stack_b);
	last = ft_lstlast(tmp);
	(*stack_b) = (*stack_b)->next;
	last->next = tmp;
	last->next->next = NULL;	
}

void	rr(t_list *stack_a, t_list *stack_b)
{
	ra(&stack_a);
	rb(&stack_b);
}

void	rra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *stack_a;
	last = ft_lstlast(tmp);
	while (tmp)
	{
		if (tmp->next->next == NULL)
		{
			 tmp->next = NULL;
			 break ;
		}
		tmp = tmp->next;
	}
	last->next = *stack_a;
	*stack_a = last;
}

void	rrb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *stack_b;
	last = ft_lstlast(tmp);
	while (tmp)
	{
		if (tmp->next->next == NULL)
		{
			 tmp->next = NULL;
			 break ;
		}
		tmp = tmp->next;
	}
	last->next = *stack_b;
	*stack_b = last;
}