/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:08:17 by brguicho          #+#    #+#             */
/*   Updated: 2024/03/28 22:18:31 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack, int argc, char **argv)
{
	int				i;
	int				j;
	char			**args;

	i = 1;
	while (i < argc)
	{
		j = 0;
		args = ft_split(argv[i], ' ');
		if (!check_argv(args) || !args)
		{
			write(2, "Error\n", 6);
			ft_free_tab(args);
			ft_lstclear(&stack->stack_a, free);
			return ;
		}
		while (args[j])
		{
			put_in_stack(stack, args[j], args);
			j++;
		}
		i++;
		ft_free_tab(args);
	}
}

void	put_in_stack(t_stack *stack, char *arg, char **args)
{
	long long int	*num;

	num = ft_calloc(sizeof(long long int *), 1);
	*num = ft_atol(arg);
	if (check_double_int(stack, num) || *num > INT_MAX || *num < INT_MIN)
	{
		write(2, "Error\n", 6);
		ft_free_tab(args);
		ft_lstclear(&stack->stack_a, free);
		free(num);
		exit(1);
	}
	ft_lstadd_back(&stack->stack_a, ft_lstnew(num));
}
