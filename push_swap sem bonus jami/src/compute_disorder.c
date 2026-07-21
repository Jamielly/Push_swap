/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 15:11:29 by jamsilva          #+#    #+#             */
/*   Updated: 2026/07/21 15:11:58 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_number *stack)
{
	t_number	*current;
	t_number	*checker;
	int			mistakes;
	int			total_pairs;

	mistakes = 0;
	total_pairs = 0;
	current = stack;
	while (current && current->next)
	{
		checker = current->next;
		while (checker)
		{
			total_pairs++;
			if (current->value > checker->value)
				mistakes++;
			checker = checker->next;
		}
		current = current->next;
	}
	if (total_pairs == 0)
		return (0);
	return ((float)mistakes / total_pairs);
}
