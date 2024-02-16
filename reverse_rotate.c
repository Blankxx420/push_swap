/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:16:10 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/16 09:40:17 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *stack;
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
	last->next = *stack;
	*stack = last;
}

void	rrb(t_list **stack)
{
	reverse_rotate(stack);
	ft_putendl_fd("rrb", 1);
}

void	rra(t_list **stack)
{
	reverse_rotate(stack);
	ft_putendl_fd("rra", 1);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
}