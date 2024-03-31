/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 22:58:53 by brguicho          #+#    #+#             */
/*   Updated: 2024/04/01 00:25:22 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_move(t_best best, t_stack *data)
{
	if (best.nb_a > 0 && best.type_a == 1)
	{
		ra(&data->stack_a);
		ft_putendl_fd("ra", 1);
	}
	if (best.nb_a > 0 && best.type_a == 2)
	{
		rra(&data->stack_a);
		ft_putendl_fd("rra", 1);
	}
	if (best.nb_b > 0 && best.type_b == 1)
	{
		rb(&data->stack_b);
		ft_putendl_fd("rb", 1);
	}
	if (best.nb_b > 0 && best.type_b == 2)
	{
		rrb(&data->stack_b);
		ft_putendl_fd("rrb", 1);
	}
}

int	get_position_target(t_stack *data, t_list *b, int j)
{
	t_list		*current_st;
	long long	target;

	current_st = data->stack_a;
	target = get_target(current_st, b, get_min(data->stack_a));
	while (current_st)
	{
		if (*(long long *)current_st->content == target)
		{
			return (j);
		}
		j++;
		current_st = current_st->next;
	}
	return (j);
}
