/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 14:00:28 by luafranc          #+#    #+#             */
/*   Updated: 2026/07/21 13:25:25 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rotate(t_number **stack)
{
	t_number	*first;
	t_number	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = first;
	while (last->next)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	ra(t_number **a)
{
	do_rotate(a);
	register_cmd("ra");
}

void	rb(t_number **b)
{
	do_rotate(b);
	register_cmd("rb");
}

void	rr(t_number **a, t_number **b)
{
	do_rotate(a);
	do_rotate(b);
	register_cmd("rr");
}
