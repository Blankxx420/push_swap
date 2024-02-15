/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:02:41 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/15 12:20:19 by brguicho         ###   ########.fr       */
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
	tab = init_tab(data.stack_a);
	sort_tab(tab, ft_lstsize(data.stack_a));
	presort_stack(&data.stack_a, &data.stack_b, tab);
	ft_lstclear(&data.stack_a, free);
	ft_lstclear(&data.stack_b, free);
	free(tab);
}