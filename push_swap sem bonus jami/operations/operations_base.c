/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luafranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:59:55 by luafranc          #+#    #+#             */
/*   Updated: 2026/07/14 13:59:56 by luafranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_base(t_number **stack)
{
	t_number	*first;
	t_number	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}

void	push_base(t_number **src, t_number **dst)
{
	t_number	*node_to_push;

	if (!src || !*src)
		return ;
	node_to_push = *src;
	*src = node_to_push->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->next = *dst;
	if (*dst)
		(*dst)->prev = node_to_push;
	*dst = node_to_push;
}

void	rotate_base(t_number **stack)
{
	t_number	*first;
	t_number	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = get_last_node(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	rev_rotate_base(t_number **stack)
{
	t_number	*last;
	t_number	*before_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = get_last_node(*stack);
	before_last = last->prev;
	before_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}
