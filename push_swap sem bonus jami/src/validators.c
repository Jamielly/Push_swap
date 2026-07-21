/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luafranc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 14:01:07 by luafranc          #+#    #+#             */
/*   Updated: 2026/07/14 14:01:08 by luafranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_syntax(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (!ft_isdigit(str[i + 1]))
			return (0);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_limits(long int nbr)
{
	if (nbr > 2147483647 || nbr < -2147483648)
		return (0);
	return (1);
}

int	check_duplicate(t_number *stack, int nbr)
{
	while (stack)
	{
		if (stack->value == nbr)
			return (1);
		stack = stack->next;
	}
	return (0);
}
