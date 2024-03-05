/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:31:37 by brguicho          #+#    #+#             */
/*   Updated: 2024/03/05 14:00:58 by brguicho         ###   ########.fr       */
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

int	calculate_best_move(t_stack data)
{
	int best;
	long long min;
	int	move;
	int lst_size;
	int i;

	best = INT_MAX;
	lst_size = ft_lstsize(data.stack_b);
	i = 0;
	while (data.stack_b);
	{
		min = get_min(data.stack_a);
		if (i > lst_size / 2)
			move = (calculate_position(data.stack_b, get_target(data.stack_a, data.stack_b, min))
				+ calculate_position(data.stack_a, get_target(data.stack_a, data.stack_b, min))) - lst_size + 1;
		else
			move = (calculate_position(data.stack_b, get_target(data.stack_a, data.stack_b, min))
				+ calculate_position(data.stack_a, get_target(data.stack_a, data.stack_b, min))) - 1;
		if (move < best)
			best = move;
		data.stack_b = data.stack_b->next;
		i++;	
	}
	return (best);
}
