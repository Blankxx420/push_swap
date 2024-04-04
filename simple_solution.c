/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_solution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:49:36 by brguicho          #+#    #+#             */
/*   Updated: 2024/04/04 11:50:58 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resolve_2_and_3(t_list **stack_a)
{
	if (ft_lstsize((*stack_a)) <= 3)
	{
		if (*(long long int *)(*stack_a)->content
				> *(long long int *)(*stack_a)->next->content)
			sa((*stack_a));
		if ((*stack_a)->next->next)
		{
			if (*(long long int *)(*stack_a)->content
					> *(long long int *)(*stack_a)->next->next->content)
			{
				rra(stack_a);
				ft_printf("rra\n");
			}
			if (*(long long int *)(*stack_a)->next->content
					> *(long long int *)(*stack_a)->next->next->content)
			{
				ra(stack_a);
				ft_printf("ra\n");
				sa((*stack_a));
			}
		}
	}
}

void	resolve_4_and_5(t_list **stack_a, t_list **stack_b)
{
	long long	little;

	little = get_min(*stack_a);
	while (*(long long int *)(*stack_a)->content != little)
	{
		ra(stack_a);
		write(1, "ra\n", 3);
	}
	pb(stack_a, stack_b);
	little = get_min(*stack_a);
	while (*(long long int *)(*stack_a)->content != little)
	{
		ra(stack_a);
		write(1, "ra\n", 3);
	}
	pb(stack_a, stack_b);
	resolve_2_and_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	if (*(long long int *)(*stack_a)->content
			> *(long long int *)(*stack_a)->next->content)
		sa((*stack_a));
}
