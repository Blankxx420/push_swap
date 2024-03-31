/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:19:34 by brguicho          #+#    #+#             */
/*   Updated: 2024/04/01 00:00:45 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_stack *data)
{
	int	size_stack;

	size_stack = ft_lstsize(data->stack_a);
	if (size_stack == 2 || size_stack == 3)
	{
		resolve_2_and_3(&data->stack_a);
		return (0);
	}
	if (size_stack == 4 || size_stack == 5)
	{
		resolve_4_and_5(&data->stack_a, &data->stack_b);
		return (0);
	}
	if (size_stack > 5)
	{
		if (big_sort(data) == 1)
			return (1);
	}
	return (0);
}

int	big_sort(t_stack *data)
{
	long long int	*tab;
	t_best			best;
	t_best			current;

	tab = init_tab(data->stack_a);
	if (!tab)
		return (1);
	sort_tab(tab, ft_lstsize(data->stack_a));
	data = presort_stack(data, tab);
	resolve_2_and_3(&data->stack_a);
	calculate_best_move(data, best, current);
	ft_last_move(&data->stack_a);
	free(tab);
	return (0);
}
