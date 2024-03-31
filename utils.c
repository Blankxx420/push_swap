/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:04:54 by brguicho          #+#    #+#             */
/*   Updated: 2024/03/31 23:42:43 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	get_max(t_list *stack_a)
{
	long long	max;
	t_list		*tmp;

	max = LLONG_MIN;
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->next)
		{
			if (*(long long int *)tmp->content > max)
				max = *(long long int *)tmp->content;
		}
		tmp = tmp->next;
	}
	return (max);
}

long long int	get_nearest_max(t_list *stack_a, void *content)
{
	long long	max;

	max = LLONG_MAX;
	while (stack_a)
	{
		if (*(long long *)stack_a->content
			<= max && *(long long *)stack_a->content
			> *(long long *)content)
		{
			max = *(long long *)stack_a->content;
		}
		stack_a = stack_a->next;
	}
	return (max);
}

int	get_total(t_best *current)
{
	if (current->type_a == current->type_b)
	{
		if (current->nb_a > current->nb_b)
			current->nb_total = current->nb_a;
		else
			current->nb_total = current->nb_b;
	}
	else
		current->nb_total = current->nb_a + current->nb_b;
	return (current->nb_total);
}

void	loop_rra(t_list **stack_a, int i)
{
	while (i > 0)
	{
		rra(stack_a);
		write(1, "rra\n", 4);
		i--;
	}
}

void	loop_ra(t_list **stack_a, int i)
{
	while (i > 0)
	{
		ra(stack_a);
		write(1, "ra\n", 3);
		i--;
	}
}
