/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:08:17 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/08 14:01:04 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack, int argc, char **argv)
{
	int				i;
	int 			j;
	long long int	*num;
	char 			**args;

	i = 1;
	num = NULL;
	while (i < argc)
	{
		j = 0;
		args = ft_split(argv[i], ' ');
		if (!check_argv(args))
		{
			ft_printf("Error\n");
			ft_free_tab(args);
			ft_lstclear(&stack->stack_a, free);
			return ;
		}
		while (args[j])
		{
			num = ft_calloc(sizeof(long long int *), 1);
			*num = ft_atol(args[j]);
			if (check_double_int(stack, num))
			{
				ft_free_tab(args);
				ft_lstclear(&stack->stack_a, free);
				free(num);
				return ;
			}
			ft_lstadd_back(&stack->stack_a, ft_lstnew(num));
			j++;
		}
		i++;
		ft_free_tab(args);
	}
}