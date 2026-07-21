/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 13:59:37 by luafranc          #+#    #+#             */
/*   Updated: 2026/07/21 13:14:24 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

// ESTRUTURA DA LISTA DUPLAMENTE ENCADEADA
typedef struct s_number
{
	int				value;
	struct s_number	*next;
	struct s_number	*prev;
}	t_number;

/* ========================================================================== */
/*                                ROTEAMENTO (src/)                           */
/* ========================================================================== */

/* parse_input.c */
void		parse_input(t_number **stack_a, char **argv);
int			is_flag(char *str);

/* validators.c */
int			check_syntax(char *str);
int			check_limits(long int nbr);
int			check_duplicate(t_number *stack, int nbr);

/* ft_atol.c */
long int	ft_atol(char *str);

/* list_utils.c */
t_number	*create_node(int value);
t_number	*get_last_node(t_number *stack);
void		append_node(t_number **stack, t_number *new_node);
int			get_stack_size(t_number *stack);

/* free_utils.c */
void		free_stack(t_number **stack);
void		free_matrix(char **matrix);
void		error_exit(t_number **stack);

/* ========================================================================== */
/*                             OPERACOES (operations/)                        */
/* ========================================================================== */

/* operations_base.c */
void		swap_base(t_number **stack);
void		push_base(t_number **src, t_number **dst);
void		rotate_base(t_number **stack);
void		rev_rotate_base(t_number **stack);

/* swap_commands.c */
void		sa(t_number **a);
void		sb(t_number **b);
void		ss(t_number **a, t_number **b);

/* push_commands.c */
void		pa(t_number **b, t_number **a);
void		pb(t_number **a, t_number **b);

/* rotate_commands.c */
void		ra(t_number **a);
void		rb(t_number **b);
void		rr(t_number **a, t_number **b);

/* reverse_commands.c */
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

/* ========================================================================== */
/*                             ALGORITMOS (src/)                              */
/* ========================================================================== */

/* adaptive_tools.c */
int			is_sorted(t_number *stack);
float		compute_disorder(t_number *stack);
void		adaptive_sort(t_number **a, t_number **b);
void		execute_strategy(t_number **a, t_number **b, char *flag);

/* simple_sort.c */
void		simple_sort(t_number **a, t_number **b);
t_number	*find_min_node(t_number *stack);
void		move_min_to_top(t_number **stack, t_number *min_node);

/* medium_sort.c */
void		medium_sort(t_number **a, t_number **b);

/* complex_sort.c */
void		complex_sort(t_number **a, t_number **b);

#endif
