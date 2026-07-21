/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 14:01:40 by luafranc          #+#    #+#             */
/*   Updated: 2026/07/21 16:08:18 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_number	*stack_a;
	t_number	*stack_b;
	char		*strat;

	if (argc == 1)
		return (0);
	stack_b = NULL;
	parse_input(argv, &stack_a, &strat);
	if (!stack_a)
		return (0);
	while (argv[++i])
	{
		if (ft_strncmp(argv[i], "--bench", 8) == 0)
			get_bench()->bench_mode = 1;
		else if (is_flag(argv[i]))
			strat = argv[i];
	}
	if (!is_sorted(stack_a))
		execute_strategy(&stack_a, &stack_b, strat);
	print_benchmark();
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
