/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_solution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:49:36 by brguicho          #+#    #+#             */
/*   Updated: 2024/03/28 22:37:24 by brguicho         ###   ########.fr       */
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

long long int	get_little_min(t_list *stack_a)
{
	long long	little;
	t_list		*tmp;

	little = LLONG_MAX;
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->next)
		{
			if (*(long long int *)tmp->content < little)
				little = *(long long int *)tmp->content;
		}
		tmp = tmp->next;
	}
	return (little);
}

void	resolve_4_and_5(t_list **stack_a, t_list **stack_b)
{
	long long	little;

	little = get_little_min(*stack_a);
	while (*(long long int *)(*stack_a)->content != little)
	{
		ra(stack_a);
	}
	pb(stack_a, stack_b);
	little = get_little_min(*stack_a);
	while (*(long long int *)(*stack_a)->content != little)
	{
		ra(stack_a);
	}
	pb(stack_a, stack_b);
	resolve_2_and_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	if (*(long long int *)(*stack_a)->content
			> *(long long int *)(*stack_a)->next->content)
		sa((*stack_a));
}
