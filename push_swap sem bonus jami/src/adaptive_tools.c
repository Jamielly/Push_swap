/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 14:00:45 by luafranc          #+#    #+#             */
/*   Updated: 2026/07/21 13:24:02 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_number *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

float	compute_disorder(t_number *stack)
{
	float		mistakes;
	float		total_pairs;
	t_number	*current;
	t_number	*compare;

	mistakes = 0;
	total_pairs = 0;
	current = stack;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			total_pairs++;
			if (current->value > compare->value)
				mistakes++;
			compare = compare->next;
		}
		current = current->next;
	}
	if (total_pairs == 0)
		return (0);
	return (mistakes / total_pairs);
}

void	adaptive_sort(t_number **a, t_number **b)
{
	float	disorder;

	if (!a || !*a)
		return ;
	disorder = compute_disorder(*a);
	get_bench()->disorder = disorder;
	if (disorder < 0.2)
	{
		get_bench()->strategy_name = "Adaptive / O(n^2)";
		simple_sort(a, b);
	}
	else if (disorder < 0.5)
	{
		get_bench()->strategy_name = "Adaptive / O(n*sqrt(n))";
		medium_sort(a, b);
	}
	else
	{
		get_bench()->strategy_name = "Adaptive / O(n log n)";
		complex_sort(a, b);
	}
}

void	execute_strategy(t_number **a, t_number **b, char *flag)
{
	if (!flag || ft_strncmp(flag, "--adaptive", 11) == 0)
		adaptive_sort(a, b);
	else if (ft_strncmp(flag, "--simple", 9) == 0)
	{
		get_bench()->strategy_name = "Simple / O(n^2)";
		simple_sort(a, b);
	}
	else if (ft_strncmp(flag, "--medium", 9) == 0)
	{
		get_bench()->strategy_name = "Medium / O(n*sqrt(n))";
		medium_sort(a, b);
	}
	else if (ft_strncmp(flag, "--complex", 10) == 0)
	{
		get_bench()->strategy_name = "Complex / O(n log n)";
		complex_sort(a, b);
	}
}

int	is_flag(char *str)
{
	if (!str)
		return (0);
	if (ft_strncmp(str, "--adaptive", 11) == 0)
		return (1);
	if (ft_strncmp(str, "--simple", 9) == 0)
		return (1);
	if (ft_strncmp(str, "--medium", 9) == 0)
		return (1);
	if (ft_strncmp(str, "--complex", 10) == 0)
		return (1);
	if (ft_strncmp(str, "--bench", 8) == 0)
		return (1);
	return (0);
}
