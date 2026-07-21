/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luafranc <luafranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 14:00:12 by luafranc          #+#    #+#             */
/*   Updated: 2026/07/15 19:15:57 by luafranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_swap(t_number **stack)
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

void	sa(t_number **a)
{
	do_swap(a);
	register_cmd("sa");
}

void	sb(t_number **b)
{
	do_swap(b);
	register_cmd("sb");
}

void	ss(t_number **a, t_number **b)
{
	do_swap(a);
	do_swap(b);
	register_cmd("ss");
}
