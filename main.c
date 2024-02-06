/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:02:41 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/06 14:58:27 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack data;
	t_list *current;
	
	data.stack_a = NULL;
	if (argc < 3)
	{
		ft_printf("%s",
			"Wrong number of parameters: expected minimum 2 number");
		return (1);
	}
	init_stack(&data, argc, argv);
	current = data.stack_a;
	while (current)
	{
		ft_printf("%d\n", *(int *)current->content);
		current = current->next;
	}
	ft_lstclear(&data.stack_a, ft_free_tab);
}