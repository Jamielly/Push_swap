/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luafranc <luafranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 14:01:40 by luafranc          #+#    #+#             */
/*   Updated: 2026/07/24 11:53:51 by luafranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_strategy_flag(char **argv)
{
	int		i;
	char	*strat;

	i = 0;
	strat = NULL;
	while (argv[++i])
	{
		if (ft_strncmp(argv[i], "--bench", 8) == 0)
			get_bench()->bench_mode = 1;
		else if (is_flag(argv[i]))
			strat = argv[i];
	}
	return (strat);
}

int	main(int argc, char **argv)
{
	t_number	*stack_a;
	t_number	*stack_b;
	char		*strat;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	parse_input(&stack_a, argv);
	if (!stack_a)
		return (0);
	strat = get_strategy_flag(argv);
	if (!is_sorted(stack_a))
		execute_strategy(&stack_a, &stack_b, strat);
	print_benchmark();
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
