/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:54:36 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/16 14:31:06 by brguicho         ###   ########.fr       */
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

int	get_position(long long *tab, void *content, int tablen)
{
	int median;
	int quarter;

	median = tablen / 2;
	quarter = tablen / 4;
	if (*(long long int *)content >= tab[median])
		{
			if (*(long long int *)content < tab[quarter * 3])
				return(3);
			else
				return (4);
		}
	if (*(long long int *)content <= tab[median])
		{
			if (*(long long int *)content > tab[quarter])
				return (2);
			else
				return (1);
		}
	return (0);
}

void	presort_stack(t_list **stack_a, t_list **stack_b, long long *tab)
{
	int i;
	int tablen;
	int position;
	
	i = 0;
	tablen = ft_lstsize(*stack_a);
	while (i < (tablen + tablen / 2) - 2)
	{
		position = get_position(tab, (*stack_a)->content, tablen);
		check_position(stack_a, stack_b, position);
		if (position == 4 || position == 3)
		{
			if (i < tablen)
				ra(stack_a);
			else
			{
				if (position == 3)
				{
					pb(stack_a, stack_b);
					rb(stack_b);
				}
				if (position == 4)
					pb(stack_a, stack_b);
			}
		}
		i++;
	}
	while (*stack_b)
	{
		printf("la target de %lld est %lld\n", *(long long *)(*stack_b)->content, *(long long *)get_target(stack_a, stack_b));
		*stack_b = (*stack_b)->next;
	}
}

int calculate_position(t_list **stack, void *content)
{
	int pos;
	
	while (stack)
	{
		if  (*(long long int *)content != *(long long int *)(*stack)->content)
		{
			pos++;
		}
		*stack = (*stack)->next;
	}
	return (pos);
}

void *get_target(t_list **stack_a, t_list **stack_b)
{
	void *target;
	void *min;
	
	min = get_min(stack_a);
	target =  (*stack_b)->content;
	while (*stack_a)
	{
		if (*(long long *)(*stack_b)->content < *(long long *)(*stack_a)->content)
		{
			if (*(long long *)(*stack_a)->content > *(long long *)target)
				*stack_a = (*stack_a)->next;
			target = (*stack_a)->content;
		}
		if (*(long long *)(*stack_b)->content > *(long long *)(*stack_a)->content)
			target = (*stack_b)->content;
		*stack_a = (*stack_a)->next;
	}
	if (*(long long *)(*stack_b)->content == *(long long *)target)
			target = min;
	return (target);
}

void *get_min(t_list **stack)
{
	void *min;

	min = (*stack)->content;
	while (*stack)
	{
		if (*(long long *)(*stack)->content < *(long long *)min)
			min = (*stack)->content;
		*stack = (*stack)->next;
	}
	return (min);
}