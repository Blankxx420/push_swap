/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brguicho <brguicho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:37:13 by brguicho          #+#    #+#             */
/*   Updated: 2024/02/08 15:41:36 by brguicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *stack_a)
{
	char *tmp;

	if (!stack_a || !stack_a->next)
		return ; 
	tmp = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next ->content = tmp;	
}

void	sb(t_list *stack_b)
{
	char *tmp;

	if (!stack_b || !stack_b->next)
		return ;
	tmp = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next ->content = tmp;	
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_list *stack_a, t_list *stack_b)
{
	t_list *tmp;
	
	if (!stack_b)
		return ;
	tmp = stack_a;
	stack_a = stack_b;
	stack_a->next = tmp;
	stack_b = stack_b->next;
}

void	pb(t_list *stack_a, t_list *stack_b)
{
	t_list *tmp;
	
	if (!stack_a)
		return ;
	tmp = stack_b->next;
	stack_b = stack_a;
	stack_b->next = tmp;
	stack_a = stack_a->next;
}