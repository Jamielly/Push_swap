/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 14:01:27 by luafranc          #+#    #+#             */
/*   Updated: 2026/07/21 13:22:20 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_error(t_number **stack, char **matrix)
{
	free_matrix(matrix);
	error_exit(stack);
}

static void	process_numbers(t_number **stack, char **matrix)
{
	int			i;
	long int	nbr;
	t_number	*new_n;

	i = -1;
	while (matrix[++i])
	{
		if (!check_syntax(matrix[i]))
			free_error(stack, matrix);
		nbr = ft_atol(matrix[i]);
		if (!check_limits(nbr) || check_duplicate(*stack, (int)nbr))
			free_error(stack, matrix);
		new_n = create_node((int)nbr);
		if (!new_n)
			free_error(stack, matrix);
		append_node(stack, new_n);
	}
}

void	parse_input(t_number **stack, char **argv)
{
	int		i;
	char	**matrix;

	i = 1;
	while (argv[i])
	{
		if (is_flag(argv[i]))
		{
			i++;
			continue ;
		}
		matrix = ft_split(argv[i], ' ');
		if (!matrix || !*matrix)
			free_error(stack, matrix);
		process_numbers(stack, matrix);
		free_matrix(matrix);
		i++;
	}
}
