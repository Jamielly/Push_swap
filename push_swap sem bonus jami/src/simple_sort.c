/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 14:01:53 by luafranc          #+#    #+#             */
/*   Updated: 2026/07/21 13:21:46 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_number	*find_min_node(t_number *stack)
{
	t_number	*min_node;
	int			min_val;

	if (!stack)
		return (NULL);
	min_node = stack;
	min_val = stack->value;
	while (stack)
	{
		if (stack->value < min_val)
		{
			min_val = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

void	move_min_to_top(t_number **a, t_number *min_node)
{
	int			size;
	int			pos;
	t_number	*tmp;

	size = get_stack_size(*a);
	pos = 0;
	tmp = *a;
	while (tmp && tmp != min_node)
	{
		pos++;
		tmp = tmp->next;
	}
	while (*a != min_node)
	{
		if (pos <= size / 2)
			ra(a);
		else
			rra(a);
	}
}

void	simple_sort(t_number **a, t_number **b)
{
	t_number	*min_node;

	while (*a)
	{
		min_node = find_min_node(*a);
		move_min_to_top(a, min_node);
		pb(a, b);
	}
	while (*b)
		pa(b, a);
}
