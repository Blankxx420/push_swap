/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:02:41 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/10 14:26:18 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> //norm

int main(int argc, char **argv)
{
	t_stack data;
	t_list *current;
	//t_list *current2;
	
	data.stack_a = NULL;
	data.stack_b = NULL;
	init_stack(&data, argc, argv);
	rra(&data.stack_a);
	current = data.stack_a;
	//current2 = data.stack_b;
	// while (current)
	// {
	// 	printf("%lld\n", *(long long int *)current->content);
	// 	current = current->next;
	// }
	while (current)
	{
		printf("%lld\n", *(long long int *)current->content);
		current = current->next;
	}
	ft_lstclear(&data.stack_a, free);
	ft_lstclear(&data.stack_b, free);
}