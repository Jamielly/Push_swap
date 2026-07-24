*This project was developed as part of the 42 curriculum by **jamsilva** and **luafranc**.*

# push_swap

## About

`push_swap` is a sorting algorithm project from the 42 curriculum.

The goal is to sort a stack of integers using two stacks (`a` and `b`) and a
limited set of stack operations while producing the smallest possible sequence
of instructions.

The program validates the input, detects invalid cases (duplicates, overflow,
invalid syntax), and prints the operations required to sort the stack.

---

## Features

- Input validation
- Duplicate detection
- Integer overflow protection
- Memory leak free
- Norm compliant
- Multiple sorting strategies
- Adaptive strategy selection
- Optional benchmark mode

---

## Sorting Strategies

The project includes four available strategies.

| Strategy | Flag | Description |
|----------|------|-------------|
| Simple | `--simple` | Optimized for very small inputs. |
| Medium | `--medium` | Chunk-based sorting for medium and large stacks. |
| Complex | `--complex` | Binary radix sort using indexed values. |
| Adaptive *(default)* | `--adaptive` | Automatically selects the most appropriate strategy. |

---

## Adaptive Strategy

When no flag is provided, `push_swap` automatically chooses the sorting
strategy based on the input size and its level of disorder.

The disorder score is computed before sorting using the ratio of inverted pairs
(Kendall Tau distance):

```
disorder = inverted_pairs / total_pairs
```

- `0.0` → already sorted
- `1.0` → completely reversed

Selection rules:

- **n ≤ 5**
  - Uses the optimized small-sort implementation.
- **Nearly sorted small inputs**
  - Uses the Simple strategy.
- **Highly disordered medium inputs**
  - Uses Binary Radix Sort.
- **All remaining cases**
  - Uses Chunk Sort.

---

## Algorithms

### Simple

Uses specialized routines for stacks of size 2, 3 and 5.

For larger inputs, the smallest value is repeatedly moved to stack **b** using
the shortest rotation path before rebuilding the sorted stack.

---

### Medium

Chunk Sort.

Values are first indexed from `0` to `n - 1`.

The stack is divided into chunks, pushing elements into stack **b** while
keeping retrieval efficient.

The remaining elements are sorted, then values are pushed back in descending
order.

---

### Complex

Binary LSD Radix Sort.

Values are indexed before sorting.

For each bit:

- bit = 0 → `pb`
- bit = 1 → `ra`

After each pass, all elements are restored with `pa`.

---

## Build

```bash
make
make clean
make fclean
make re
```

Compilation flags:

```text
-Wall -Wextra -Werror
```

---

## Usage

Default (Adaptive):

```bash
./push_swap 4 67 3 87 23
```

Force a strategy:

```bash
./push_swap --simple 5 4 3 2 1

./push_swap --medium $(shuf -i 0-99 -n 50 | tr '\n' ' ')

./push_swap --complex $(shuf -i 0-999 -n 100 | tr '\n' ' ')

./push_swap --adaptive 5 4 3 2 1
```

Benchmark mode:

```bash
./push_swap --bench --simple 5 4 3 2 1
```

Count operations:

```bash
ARG="4 67 3 87 23"

./push_swap $ARG | wc -l
```

Validate using the official checker:

```bash
ARG="4 67 3 87 23"

./push_swap $ARG | ./checker_linux $ARG
```

---

## Error Handling

Examples:

```bash
./push_swap 0 one 2 3
# Error

./push_swap 3 2 3
# Error

./push_swap 2147483648
# Error

./push_swap
# No output
```

---

## Project Structure

```
include/
libft/
src/
operations/
parsing/
sorting/
utils/
```

---

## References

- 42 Subject — push_swap
- Think Like a Programmer — V. Anton Spraul
- The Programmer's Brain — Felienne Hermans
- Binary Radix Sort
- Chunk-based Sorting
- Big-O Notation
- 42 push_swap Visualizer

---

## AI Assistance

AI tools (Replit Agent and Cursor) were used during the development process for:

- project scaffolding;
- Makefile boilerplate;
- initial data structure suggestions;
- parsing helpers;
- algorithm skeletons.

Every generated snippet was reviewed, rewritten when necessary, adapted to the
42 Norm, tested, and fully understood by both authors. The final implementation
and debugging were completed manually.

---

## Authors

| Login | Contributions |
|-------|---------------|
| **jamsilva** | Sorting algorithms, adaptive mode, disorder metric, benchmark mode, indexing, integration and documentation. |
| **luafranc** | Stack operations, parsing, validation, memory management, Makefile, project architecture and initial implementation. |

Both authors reviewed the entire codebase and are able to explain every part of
the implementation.
