/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:02:41 by brguicho          #+#    #+#             */
/*   Updated: 2024/03/28 23:10:23 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_last_move(t_list *stack_a)
{
	long long	min;
	int			i;
	int			size;
	t_list		*current;

	current = stack_a;
	size = ft_lstsize(stack_a);
	min = get_min(stack_a);
	i = 0;
	while (current && *(long long *)current->content != min)
	{
		i++;
		current = current->next;
	}
	if (i > size / 2)
	{
		i = size - i;
		while (i > 0)
		{
			rra(&stack_a);
			printf("rra\n");
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			ra(&stack_a);
			printf("ra\n");
			i--;
		}
	}
}

int	main(int argc, char **argv)
{
	t_stack	data;

	data.stack_a = NULL;
	data.stack_b = NULL;
	init_stack(&data, argc, argv);
	if (!data.stack_a)
		return (0);
	if (push_swap(&data) == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	ft_lstclear(&data.stack_a, free);
}
