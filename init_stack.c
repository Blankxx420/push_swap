/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:08:17 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/06 12:00:47 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack, int argc, char **argv)
{
	int	i;
	int	*num;

	i = 1;
	num = NULL;
	while (i < argc)
	{
		num = ft_calloc(sizeof(int *), 1);
		*num = ft_atoi(argv[i]);
		ft_printf("num:%d\n", *num);
		ft_lstadd_back(&stack->stack_a, ft_lstnew(num));
		i++;
	}
}