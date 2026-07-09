# Push_swap
This project has been created as part of the study of C

push_swap/
├── Makefile                   ← make / make bonus / make re
├── README.md                  ← já com a estrutura exigida pela 42
├── include/
│   └── push_swap.h            ← structs t_node, t_stack, t_ctx + protótipos
├── src/
│   ├── main.c                 ← ponto de entrada, parse de flags
│   ├── stack.c                ← estrutura de dados (push, pop, rotate, move_top)
│   ├── operations.c           ← as 11 operações: sa sb ss pa pb ra rb rr rra rrb rrr
│   ├── parse.c                ← validação dos argumentos + tratamento de erros
│   ├── disorder.c             ← métrica de desordem (Kendall-tau)
│   ├── sort_simple.c          ← O(n²) — insertion sort adaptado
│   ├── sort_medium.c          ← O(n√n) — chunk sort com extração por max
│   ├── sort_complex.c         ← O(n log n) — radix sort LSD binário
│   ├── sort_adaptive.c        ← adaptativo baseado na métrica de desordem
│   ├── bench.c                ← saída de benchmark (stderr com --bench)
│   └── utils.c                ← ft_atol, ctx_free
├── bonus/
│   └── checker.c              ← lê operações do stdin e verifica OK/KO
└── libft/                     ← libft básica incluída (ft_putchar, ft_strlen, etc.)
