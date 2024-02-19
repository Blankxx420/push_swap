/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:54:36 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/19 15:46:59 by brguicho         ###   ########.fr       */
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
	//long long min;
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
	t_list *tmp = *stack_b;
	t_list *tmp2 = *stack_b;
	//t_list *tmp3 = *stack_a;
	//min = get_min(tmp3);
	while (tmp2)
	{
		position = calculate_position(tmp, *(long long *)tmp2->content);// + calculate_position(tmp3, get_target(tmp3, tmp2, min));
		
		printf("%d\n", position);
		tmp2 = tmp2->next;
	}
}

int calculate_position(t_list *stack, long long content)
{
	int pos;
	
	pos = 0;
	while (stack)
	{
		if (content != *(long long *)stack->content)
			pos++;
		if (content == *(long long *)stack->content)
			break;
		stack = stack->next;
	}
	return (pos);
}

long long get_target(t_list *stack_a, t_list *stack_b, long long min)
{
	long long target;
	
	target = *(long long *)stack_b->content;
	
	while (stack_a)
	{
		if (*(long long *)stack_b->content < *(long long *)stack_a->content)
		{
			if (*(long long *)stack_a->content > target)
				target = *(long long *)stack_a->content;
		}
		else 
			target = *(long long *)stack_b->content;
		stack_a = stack_a->next;
	}
	if (target == *(long long *)stack_b->content)
			target = min;
	return (target);
}

long long get_min(t_list *stack)
{
	long long min;

	min = *(long long *)stack->content;
	while (stack)
	{
		if (*(long long *)stack->content < min)
			min = *(long long *)stack->content;
		stack = stack->next;
	}
	return (min);
}