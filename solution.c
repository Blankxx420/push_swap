/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:31:37 by brguicho          #+#    #+#             */
/*   Updated: 2024/03/18 09:50:14 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long get_target(t_list *stack_a, t_list *stack_b, long long min)
{
	long long target;
	t_list *tmp;

	tmp = stack_a;
	
	target = *(long long *)stack_b->content;
	
	while (stack_a)
	{
		if (*(long long *)stack_b->content > *(long long *)stack_a->content)
		{
				target = get_nearest_max(tmp, stack_b->content);
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

t_stack calculate_best_move(t_stack data)
{
	t_best best;
	t_best current;
	t_list *current_st;
	t_list *b;
	int i;
	int j;
	long long target;

	i = 0;
	current.size_a = ft_lstsize(data.stack_a);
	current.size_b = ft_lstsize(data.stack_b);
	best.nb_total = INT_MAX;
	b = data.stack_b;
	while (b)
	{
		j = 0;
		current_st = data.stack_a;
		target = get_target(data.stack_a, b, get_min(data.stack_a));
		while (current_st)
		{	
			if (*(long long *)current_st->content == target)
				break;
			j++;
			current_st = current_st->next;
		}
		current.nb_b = i;
		current.nb_a = j;
		get_type(i, j, &current);
		current.nb_total = get_total(&current);
		if (current.nb_total <= best.nb_total)
			best = current;
		i++;
		b = b->next;
	}
	data = play_move(best, data);
	if (data.stack_b)
	{
		calculate_best_move(data);
	}
	return (data);
}

void	get_type(int i, int j, t_best *current)
{
	if (i > current->size_b / 2)
		current->type_b = 2;
	else
		current->type_b = 1;
	if (j > current->size_a / 2)
		current->type_a = 2;
	else
		current->type_b = 1;
}

t_stack play_move(t_best best, t_stack data)
{
	printf("a:%d, b:%d\n", best.nb_a, best.nb_b);
	while ((best.nb_a > 0) | (best.nb_b > 0))
	{
		
		if (best.type_a != best.type_b)
		{
			ra(&data.stack_a);
			ft_putendl_fd("ra", 1);
			best.nb_a--;
			rb(&data.stack_b);
			ft_putendl_fd("rb", 1);
			best.nb_b--;
		}
		if (best.type_a == best.type_b && best.type_a == 1)
		{
			if (best.nb_a > 0 && best.nb_b > 0)
			{
				rr(data.stack_a, data.stack_b);
				best.nb_b--;
				best.nb_a--;
			}
			if (best.nb_a < 0 && best.nb_b > 0)
			{
				rb(&data.stack_b);
				ft_putendl_fd("rb", 1);
				best.nb_b--;
			}
			if (best.nb_a > 0 && best.nb_b < 0)
			{
				ra(&data.stack_a);
				ft_putendl_fd("ra", 1);
				best.nb_a--;
			}
		}
		if (best.type_a == best.type_b && best.type_a == 2)
		{
			if (best.nb_a > 0 && best.nb_b > 0)
			{
				rrr(&data.stack_a, &data.stack_b);
				best.nb_b--;
				best.nb_a--;
			}
			if (best.nb_a < 0 && best.nb_b > 0)
			{
				rrb(&data.stack_b);
				ft_putendl_fd("rrb", 1);
				best.nb_b--;
			}
			if (best.nb_a > 0 && best.nb_b < 0)
			{
				rra(&data.stack_a);
				ft_putendl_fd("rra", 1);
				best.nb_a--;
			}
		}
	}
	pa(&data.stack_a, &data.stack_b);
	return(data);
}