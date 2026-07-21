/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 14:01:00 by luafranc          #+#    #+#             */
/*   Updated: 2026/07/21 13:23:05 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	get_average(t_number *stack)
{
	long	sum;
	int		count;

	sum = 0;
	count = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		sum += stack->value;
		count++;
		stack = stack->next;
	}
	if (count == 0)
		return (0);
	return (sum / count);
}

void	push_chunks_to_b(t_number **a, t_number **b)
{
	long	avg;
	int		size;
	int		pushed;

	while (*a)
	{
		avg = get_average(*a);
		size = get_stack_size(*a);
		pushed = 0;
		while (size > 0 && *a)
		{
			if ((*a)->value <= avg)
			{
				pb(a, b);
				pushed++;
			}
			else
				ra(a);
			size--;
		}
		if (pushed == 0 && *a)
			pb(a, b);
	}
}

t_number	*find_max_node(t_number *stack)
{
	t_number	*max_node;
	int			max_val;

	if (!stack)
		return (NULL);
	max_node = stack;
	max_val = stack->value;
	while (stack)
	{
		if (stack->value > max_val)
		{
			max_val = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

void	move_max_to_top(t_number **b, t_number *max_node)
{
	int			size;
	int			pos;
	t_number	*tmp;

	size = get_stack_size(*b);
	pos = 0;
	tmp = *b;
	while (tmp && tmp != max_node)
	{
		pos++;
		tmp = tmp->next;
	}
	while (*b != max_node)
	{
		if (pos <= size / 2)
			rb(b);
		else
			rrb(b);
	}
}

void	medium_sort(t_number **a, t_number **b)
{
	t_number	*max_node;

	push_chunks_to_b(a, b);
	while (*b)
	{
		max_node = find_max_node(*b);
		move_max_to_top(b, max_node);
		pa(b, a);
	}
}
