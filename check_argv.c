/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:27:34 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/12 09:37:00 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_argv(char **args)
{
	int	i;
	int	j;
	
	i = 0;
	while (args[i])
	{
		j = 0;
		if (check_len_nbr(args[i]) > 11)
			return (0);
		while (args[i][j])
		{
			if ((args[i][j] == '+' || args[i][j] == '-') && !ft_isdigit(args[i][j + 1]))
				return (0);
			if ((args[i][j] == '+' || args[i][j] == '-') && ft_isdigit(args[i][j - 1]) && j != 0)
				return (0);
			if (ft_isalpha(args[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int check_double_int(t_stack *stack, long long int *num)
{
	t_list *current;
	
	current = stack->stack_a;
	while (current)
	{
		if (*(long long int *)current->content == *num)
			return (1);
		current = current->next;
	}
	return (0);
}

int check_len_nbr(char *arg)
{
	int	i;
	int len;

	i = 0;
	len = 0;
	while (arg[i] == '0' || arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]))
			len++;
		i++;
	}
	return (len);
}