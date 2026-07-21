*This project has been created as part of the 42 curriculum by jamsilva, luafranc*

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

## Resources
References:
- Think Like a Programmer (V. Anton Spraul) – Problem-solving strategies
- The Programmer’s Brain (Felienne Hermans) – Cognitive processes in coding
- Sorting algorithms — Wikipedia
- Radix sort — Wikipedia
- Big-O notation — Wikipedia
- 42 push_swap visualizer

## AI Usage:
AI (Replit Agent) was used to assist with the following tasks and project components:
- Scaffolding: Initial directory structure and Makefile rules
- Data Structures: Definitions of t_number and t_bench structs within include/push_swap.h
- Parsing & Logic: Helper logic for ft_atol.c and the mathematical implementation of the compute_disorder function in src/adaptive_tools.c
- Sorting Skeletons: Basic control flow for the four required strategies: Simple, Medium, Complex, and Adaptive

In accordance with 42 guidelines, all generated code was manually reviewed, refactored for Norm compliance, and debugged by both team members to ensure total ownership of the implementation