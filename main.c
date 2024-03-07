/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:02:41 by brguicho          #+#    #+#             */
/*   Updated: 2024/03/06 22:03:26 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_stack data;
	long long int *tab;
	
	data.stack_a = NULL;
	data.stack_b = NULL;
	init_stack(&data, argc, argv);
	if(!data.stack_a)
		return (0);
	tab = init_tab(data.stack_a);
	sort_tab(tab, ft_lstsize(data.stack_a));
	data = presort_stack(data, tab);
	printf("best move : %lld\n", calculate_best_move(data));
	ft_print_linked_list(&data.stack_a);
	ft_printf("\n");
	ft_print_linked_list(&data.stack_b);
	ft_lstclear(&data.stack_a, free);
	ft_lstclear(&data.stack_b, free);
	free(tab);
}