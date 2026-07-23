/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luafranc <luafranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 14:00:03 by luafranc          #+#    #+#             */
/*   Updated: 2026/07/23 14:50:00 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	do_rev_rotate(t_number **stack)
{
	t_number	*first;
	t_number	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	last = get_last_node(*stack);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*stack = last;
	return (1);
}

void	rra(t_number **a)
{
	if (do_rev_rotate(a))
		register_cmd("rra");
}

void	rrb(t_number **b)
{
	if (do_rev_rotate(b))
		register_cmd("rrb");
}

void	rrr(t_number **a, t_number **b)
{
	int	rotated;

	rotated = do_rev_rotate(a);
	rotated |= do_rev_rotate(b);
	if (rotated)
		register_cmd("rrr");
}
