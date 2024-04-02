/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:02:41 by brguicho          #+#    #+#             */
/*   Updated: 2024/04/02 22:00:36 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
