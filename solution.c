/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:31:37 by brguicho          #+#    #+#             */
/*   Updated: 2024/03/04 10:31:57 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long get_target(t_list *stack_a, t_list *stack_b, long long min)
{
	long long target;
	
	target = *(long long *)stack_b->content;
	
	while (stack_a)
	{
		if (*(long long *)stack_b->content < *(long long *)stack_a->content)
		{
			if (*(long long *)stack_a->content > target)
				target = *(long long *)stack_a->content;
		}
		else 
			target = *(long long *)stack_b->content;
		stack_a = stack_a->next;
	}
	if (target == *(long long *)stack_b->content)
			target = min;
	return (target);
}

long long get_min(t_list *stack)
{
	long long min;

	min = *(long long *)stack->content;
	while (stack)
	{
		if (*(long long *)stack->content < min)
			min = *(long long *)stack->content;
		stack = stack->next;
	}
	return (min);
}