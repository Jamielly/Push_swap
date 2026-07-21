/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 14:01:14 by luafranc          #+#    #+#             */
/*   Updated: 2026/07/21 13:22:03 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_values(t_number **stack, int min_val, int restore)
{
	t_number	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (restore)
			tmp->value += min_val;
		else
			tmp->value -= min_val;
		tmp = tmp->next;
	}
}

int	get_max_bits(t_number *stack)
{
	int	max;
	int	max_bits;

	max = stack->value;
	max_bits = 0;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	complex_sort(t_number **a, t_number **b)
{
	int	max_bits;
	int	size;
	int	i;
	int	j;
	int	min_val;

	min_val = find_min_node(*a)->value;
	shift_values(a, min_val, 0);
	max_bits = get_max_bits(*a);
	size = get_stack_size(*a);
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if ((((*a)->value) >> i) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (*b)
			pa(b, a);
	}
	shift_values(a, min_val, 1);
}
