/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_solution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:49:36 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/12 15:05:35 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	resolve_2_and_3(t_list **stack_a)
{
	if (ft_lstsize((*stack_a)) <= 3)
	{
		if (*(long long int *)(*stack_a)->content > *(long long int *)(*stack_a)->next->content)
		{
			sa((*stack_a));
			ft_printf("sa\n");
		}
		if ((*stack_a)->next->next)
		{
			if (*(long long int *)(*stack_a)->content > *(long long int *)(*stack_a)->next->next->content)
			{
				rra(stack_a);
				ft_printf("rra\n");
			}

			if (*(long long int *)(*stack_a)->next->content > *(long long int *)(*stack_a)->next->next->content)
			{
				rra(stack_a);
				ft_printf("rra\n");
				sa((*stack_a));
				ft_printf("sa\n");
			}
		}
	}
}

void	resolve_4_and_5(t_list **stack_a, t_list **stack_b)
{
	long long little;
	(void) stack_b;

	little = 0;
	while ((*stack_a))
	{
		if ((*stack_a)->next)
		{
			if (*(long long int *)(*stack_a)->content < *(long long int *)(*stack_a)->next->content)
				little =  *(long long int *)(*stack_a)->content;
			(*stack_a) = (*stack_a)->next;
		}
	}
	printf("%lld\n", little);
}