/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 22:36:32 by brguicho          #+#    #+#             */
/*   Updated: 2024/03/31 23:43:46 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_last_move(t_list **stack_a)
{
	long long	min;
	int			i;
	int			size;
	t_list		*current;

	current = *stack_a;
	size = ft_lstsize(*stack_a);
	ft_printf("size dans lastmove %i\n", size);
	min = get_min(*stack_a);
	i = 0;
	while (current && *(long long *)current->content != min)
	{
		i++;
		current = current->next;
	}
	if (i > size / 2)
	{
		i = size - i;
		loop_rra(stack_a, i);
	}
	else
	{
		loop_ra(stack_a, i);
	}
}
