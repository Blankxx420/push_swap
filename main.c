/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:02:41 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/14 15:46:15 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_stack data;
	long long int *tab;
	//t_list *current;
	//t_list	*current2;
	
	data.stack_a = NULL;
	data.stack_b = NULL;
	init_stack(&data, argc, argv);
	tab = init_tab(data.stack_a);
	sort_tab(tab, ft_lstsize(data.stack_a));
	sort_stack(&data.stack_a, &data.stack_b, tab);
	//current = data.stack_a;
	//current2 = data.stack_b;
	// while (current)
	// {
	// 	printf("%lld\n", *(long long int *)current->content);
	// 	current = current->next;
	// }
	// while (current2)
	// {
	// 	printf("%lld\n", *(long long int *)current2->content);
	// 	current2 = current2->next;
	// }
	
	ft_lstclear(&data.stack_a, free);
	ft_lstclear(&data.stack_b, free);
}