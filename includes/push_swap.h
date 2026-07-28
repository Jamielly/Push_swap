/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luafranc <luafranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:59:37 by luafranc          #+#    #+#             */
/*   Updated: 2026/07/24 13:29:23 by luafranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_number
{
	int				value;
	struct s_number	*next;
	struct s_number	*prev;
}	t_number;

void		sort_three(t_number **a);
void		parse_input(t_number **stack_a, char **argv);
int			is_flag(char *str);

int			check_syntax(char *str);
int			check_limits(long int nbr);
int			check_duplicate(t_number *stack, int nbr);

long int	ft_atol(char *str);

t_number	*create_node(int value);
t_number	*get_last_node(t_number *stack);
void		append_node(t_number **stack, t_number *new_node);
int			get_stack_size(t_number *stack);

void		free_stack(t_number **stack);
void		free_matrix(char **matrix);
void		error_exit(t_number **stack);

void		sa(t_number **a);
void		sb(t_number **b);
void		ss(t_number **a, t_number **b);

void		pa(t_number **b, t_number **a);
void		pb(t_number **a, t_number **b);

void		ra(t_number **a);
void		rb(t_number **b);
void		rr(t_number **a, t_number **b);

void		rra(t_number **a);
void		rrb(t_number **b);
void		rrr(t_number **a, t_number **b);

typedef struct s_bench {
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		total;
	int		bench_mode;
	char	*strategy_name;
	float	disorder;
}	t_bench;

t_bench		*get_bench(void);
void		register_cmd(char *cmd);
void		print_benchmark(void);

int			is_sorted(t_number *stack);
float		compute_disorder(t_number *stack);
void		adaptive_sort(t_number **a, t_number **b);
void		execute_strategy(t_number **a, t_number **b, char *flag);

void		simple_sort(t_number **a, t_number **b);
t_number	*find_min_node(t_number *stack);
void		move_min_to_top(t_number **stack, t_number *min_node);

void		medium_sort(t_number **a, t_number **b);

void		complex_sort(t_number **a, t_number **b);

#endif
