/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:54:36 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/14 15:47:43 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int *init_tab(t_list *stack_a)
{
	long long int *tab;
	int i;

	i = 0;
	tab = malloc(sizeof(long long int) * ft_lstsize(stack_a));
	while(stack_a)
	{
		tab[i] = *(long long int *)stack_a->content;
		stack_a = stack_a->next;
		i++;
	}
	return (tab);
}

long long int *sort_tab(long long int *tab, int size)
{
	int i;
	int cursor;
	long long int tmp;
	i = 0;
	while (i < size - 1)
	{
		cursor = i + 1;
		while (cursor < size)
		{	
			if (tab[i] > tab[cursor])
			{
				tmp = tab[cursor];
				tab[cursor] = tab[i];
				tab[i] = tmp;
			}
			cursor++;
		}
		i++;
	}
	return (tab);
}

long long int calculate_median(int size, long long int *tab)
{
	long long int median;
	
	median = (tab[size / 2] + tab[(size / 2) + 1]) / 2;
	return (median);
}

void	sort_stack(t_list **stack_a, t_list **stack_b, long long *tab)
{
	int median;
	int quarter;
	int tablen = ft_lstsize(*stack_a);
	int i = 0;
	median = tablen / 2;
	quarter = tablen / 4;
	median = calculate_median(ft_lstsize(*stack_a), tab);
	while (i < tablen)
	{
		if (*(long long int *)(*stack_a)->content > tab[median])
		{
			if (*(long long int *)(*stack_a)->content < tab[quarter * 3])
			{
				pb(stack_a, stack_b);
				ft_printf("pb\n");
				rb(stack_b);
				ft_printf("rb\n");
			}
			else
			{
				pb(stack_a, stack_b);
				ft_printf("pb\n");
			}
		}
		else
		{
			ra(stack_a);
			ft_printf("ra\n");
		}
		i++;
	}
}