/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_presort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 09:19:34 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/16 10:19:23 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_position(t_list **stack_a, t_list **stack_b, int position)
{
	if (position == 1)
	{
		pb(stack_a, stack_b);
		rb(stack_b);
	}
	if (position == 2)
		pb(stack_a, stack_b);
}
