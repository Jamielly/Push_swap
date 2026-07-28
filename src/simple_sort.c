/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luafranc <luafranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 14:01:53 by luafranc          #+#    #+#             */
/*   Updated: 2026/07/24 13:59:54 by luafranc         ###   ########.fr       */
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

void	sort_three(t_number **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && first > third)
		ra(a);
	else if (second > first && second > third)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	simple_sort(t_number **a, t_number **b)
{
	t_number	*min_node;
	int			size;

	size = get_stack_size(*a);
	if (size == 2 && (*a)->value > (*a)->next->value)
	{
		sa(a);
		return ;
	}
	if (size == 3)
	{
		sort_three(a);
		return ;
	}
	while (get_stack_size(*a) > 3)
	{
		min_node = find_min_node(*a);
		move_min_to_top(a, min_node);
		pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(b, a);
}
