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



*This project has been created as part of the 42 curriculum by login1, login2.*

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 school curriculum.
The goal is to sort a stack of integers using two stacks (`a` and `b`) and a
restricted set of operations, producing the shortest possible sequence of moves.

The project implements **four distinct strategies** that the program can select
at runtime based on a strategy flag or automatically via a disorder metric:

| Strategy | Flag | Complexity | Best for |
|---|---|---|---|
| Simple | `--simple` | O(n²) | Small / nearly-sorted lists |
| Medium | `--medium` | O(n√n) | Medium-sized lists |
| Complex | `--complex` | O(n log n) | Large, highly random lists |
| Adaptive | `--adaptive` *(default)* | Picks one above | Any input |

### Disorder metric

Before sorting, the program computes a **disorder score** (Kendall-tau):

```
disorder = (number of inverted pairs) / (total pairs)
```

A score of `0.0` means already sorted; `1.0` means worst possible order.

The adaptive strategy uses the score to choose the best algorithm:

| Disorder | Algorithm chosen |
|---|---|
| < 0.2 | Simple — O(n²) |
| 0.2 – 0.5 | Medium — O(n√n) |
| ≥ 0.5 | Complex — O(n log n) |

### Algorithms

**Simple (O(n²)) — Insertion sort adaptation**

Finds the minimum element in stack `a`, rotates it to the top using the
shortest path (either `ra` or `rra`), then pushes it to `b`. After all
elements are in `b` (sorted descending), pushes them all back to `a`.
Worst case: n rotations × n elements = O(n²) operations.

**Medium (O(n√n)) — Chunk-based sort**

Assigns a rank to every element. Divides the rank range into √n chunks.
For each chunk (smallest first), scans stack `a` and pushes matching
elements to `b`. After each chunk, pushes everything back to `a`.
Passes: √n. Elements per pass: n → O(n√n) operations.

**Complex (O(n log n)) — Radix sort (LSD, binary)**

Assigns ranks 0..n-1 to every element. Processes bits from LSB to MSB.
For each bit: elements with bit=0 go to `b`, elements with bit=1 rotate
in `a`. After the bit pass all of `b` goes back to `a`.
Passes: log₂(n). Moves per pass: n → O(n log n) operations.

---

## Instructions

### Compilation

```bash
cd push_swap
make          # builds push_swap binary
make bonus    # also builds checker binary
make clean    # remove object files
make fclean   # remove objects + binaries
make re       # fclean + all
```

### Usage

```bash
# Sort with default adaptive strategy
./push_swap 4 67 3 87 23

# Force a specific strategy
./push_swap --simple  5 4 3 2 1
./push_swap --medium  $(shuf -i 0-99  -n 50 | tr '\n' ' ')
./push_swap --complex $(shuf -i 0-999 -n 500 | tr '\n' ' ')

# Show benchmark metrics (sent to stderr)
./push_swap --bench --adaptive 4 67 3 87 23

# Count operations
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

# Verify correctness with checker (bonus)
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

# Large input test
shuf -i 0-9999 -n 500 > args.txt
./push_swap $(cat args.txt) | wc -l
```

### Error handling

```bash
./push_swap 0 one 2 3     # Error (non-integer)
./push_swap 3 2 3         # Error (duplicate)
./push_swap               # (no output)
```

---

## Contributors

| Login | Contributions |
|---|---|
| `login1` | TODO: fill in |
| `login2` | TODO: fill in |

---

## Resources

- [Sorting algorithms — Wikipedia](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Radix sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Big-O notation — Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation)
- [Kendall tau distance](https://en.wikipedia.org/wiki/Kendall_tau_distance)
- [42 push_swap visualizer](https://github.com/o-reo/push_swap_visualizer)

### How AI was used

AI (Replit Agent) was used to:
- Scaffold the initial file structure and Makefile
- Generate the header and struct definitions
- Provide skeleton implementations of each sorting strategy

All generated code was reviewed, debugged, and refined by both team members
to ensure full understanding and correctness.
