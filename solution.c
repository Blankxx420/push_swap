/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:31:37 by brguicho          #+#    #+#             */
/*   Updated: 2024/03/07 13:34:32 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long get_target(t_list *stack_a, t_list *stack_b, long long min)
{
	long long target;
	
	target = *(long long *)stack_b->content;
	
	while (stack_a)
	{
		if (*(long long *)stack_b->content > *(long long *)stack_a->content)
		{
				target = *(long long *)stack_a->content;
				break;
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

long long calculate_best_move(t_stack data)
{
	int best;
	int	move;
	long long num_best;
	int i;
	long long min = get_min(data.stack_a);
	t_list *start = data.stack_b;

	best = INT_MAX;
	i = 0;
	num_best = 0;
	
	while (data.stack_b)
	{
		if (i > (ft_lstsize(start)/ 2))
		{
			move = ft_lstsize(start) - ((calculate_position(start, *(long long*)data.stack_b->content)
				+ calculate_position(data.stack_a,get_target(data.stack_a, data.stack_b, min)))) + 2;
		}
		else
			move = calculate_position(start,  *(long long*)data.stack_b->content)
				+ calculate_position(data.stack_a, get_target(data.stack_a, data.stack_b, min));
		printf("move : %d\n", move);
		printf("target : %lld \n", get_target(data.stack_a, data.stack_b, min));
		if (move < best)
		{
			best = move;
			num_best = *(long long *)data.stack_b->content;
		}
		data.stack_b = data.stack_b->next;
		i++;	
	}
	return (num_best);
}
