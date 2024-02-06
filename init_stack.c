/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:08:17 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/06 14:52:03 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack, int argc, char **argv)
{
	int	i;
	int j;
	int	*num;
	char **args;

	i = 1;
	num = NULL;
	while (i < argc)
	{
		j = 0;
		args = ft_split(argv[i], ' ');
		while (args[j])
		{
			num = ft_calloc(sizeof(int *), 1);
			*num = ft_atoi(args[j]);
			ft_printf("num:%d\n", *num);
			ft_lstadd_back(&stack->stack_a, ft_lstnew(num));
			j++;
		}
		i++;
	}
}