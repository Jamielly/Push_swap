/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luafranc <luafranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 14:00:03 by luafranc          #+#    #+#             */
/*   Updated: 2026/07/15 19:16:47 by luafranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rev_rotate(t_number **stack)
{
	t_number	*first;
	t_number	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = first;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*stack = last;
}

void	rra(t_number **a)
{
	do_rev_rotate(a);
	register_cmd("rra");
}

void	rrb(t_number **b)
{
	do_rev_rotate(b);
	register_cmd("rrb");
}

void	rrr(t_number **a, t_number **b)
{
	do_rev_rotate(a);
	do_rev_rotate(b);
	register_cmd("rrr");
}
