# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/* ========== STACK ========== */

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

/* ========== CONTEXT ========== */

typedef struct s_context
{
	t_stack	*a;
	t_stack	*b;
	int		op_count;
	int		bench;
	int		silent;   /* 1 = suppress operation output (used by checker) */
	/* per-operation counters */
	int		cnt_sa;
	int		cnt_sb;
	int		cnt_ss;
	int		cnt_pa;
	int		cnt_pb;
	int		cnt_ra;
	int		cnt_rb;
	int		cnt_rr;
	int		cnt_rra;
	int		cnt_rrb;
	int		cnt_rrr;
}	t_ctx;

/* ========== STACK OPERATIONS ========== */

t_stack	*stack_new(void);
void	stack_push(t_stack *s, int value);
int		stack_pop(t_stack *s);
int		stack_peek(t_stack *s);
void	stack_free(t_stack *s);
void	stack_move_top(t_stack *src, t_stack *dst);
int		stack_is_sorted(t_stack *s);
int		stack_min(t_stack *s);
int		stack_max(t_stack *s);

/* ========== PUSH_SWAP OPERATIONS ========== */

void	op_sa(t_ctx *ctx);
void	op_sb(t_ctx *ctx);
void	op_ss(t_ctx *ctx);
void	op_pa(t_ctx *ctx);
void	op_pb(t_ctx *ctx);
void	op_ra(t_ctx *ctx);
void	op_rb(t_ctx *ctx);
void	op_rr(t_ctx *ctx);
void	op_rra(t_ctx *ctx);
void	op_rrb(t_ctx *ctx);
void	op_rrr(t_ctx *ctx);

/* ========== PARSING ========== */

int		*parse_args(int argc, char **argv, int *out_size);
int		is_valid_int(char *str);
int		has_duplicates(int *arr, int size);
void	error_exit(void);

/* ========== DISORDER ========== */

double	compute_disorder(t_stack *a);

/* ========== ALGORITHMS ========== */

void	sort_simple(t_ctx *ctx);      /* O(n²)       */
void	sort_medium(t_ctx *ctx);      /* O(n√n)      */
void	sort_complex(t_ctx *ctx);     /* O(n log n)  */
void	sort_adaptive(t_ctx *ctx);    /* adaptive     */

/* ========== BENCH ========== */

void	bench_print(t_ctx *ctx, const char *strategy, double disorder);

/* ========== UTILS ========== */

void	ctx_free(t_ctx *ctx);
long	ft_atol(const char *str);

#endif