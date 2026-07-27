# push_swap

*This project has been created as part of the 42 curriculum by jamsilva, luafranc.*

---

## Description

`push_swap` is an algorithm project focused on sorting data on a stack using a limited set of instructions and two stacks (`a` and `b`). The goal is to generate the smallest possible sequence of operations (e.g. `sa`, `pb`, `ra`) to achieve total sorting on stack `a`. This project explores algorithmic complexity (Big-O) and the implementation of multiple sorting strategies.

---

## Instructions

### Compilation

The project uses a `Makefile` with the required flags `-Wall -Wextra -Werror`.

| Command       | Action                                     |
|---------------|---------------------------------------------|
| `make`        | Compiles the `push_swap` binary              |
| `make clean`  | Removes object files                         |
| `make fclean` | Removes object files and the binary          |
| `make re`     | Recompiles the project                       |

### Usage

Run the program with a list of integers as arguments. You can also use strategy selectors:

```bash
# Default (Adaptive)
./push_swap 4 67 3 87 23

# Specific strategy
./push_swap --simple 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 100 2 45 ...
```

---

## Algorithms & Complexity

### 1. Simple Sort — O(n²)

Optimized for very small sets (n ≤ 5). It uses specialized routines for 2, 3, and 5 numbers, identifying the smallest value and pushing it to stack `b` until stack `a` is ready.

### 2. Medium Sort — O(n√n)

Uses a chunk-based strategy. Values are indexed, and the stack is divided into `√n` chunks. Elements are moved to stack `b` based on their range, reducing the number of rotations needed to find the next element.

### 3. Complex Sort — O(n log n)

Implements a binary LSD Radix Sort. By indexing values first, the algorithm sorts bit by bit. This guarantees stable performance for large sets (100 or 500 numbers) without exceeding operation limits.

### 4. Adaptive Strategy

Our custom selector measures the disorder of the stack before any move:

| Disorder                | Strategy triggered |
|--------------------------|---------------------|
| Low (< 0.2)              | Simple Sort         |
| Medium (0.2 to 0.5)      | Medium Sort         |
| High (≥ 0.5)             | Complex Sort        |

---

## Resources

### References

- *Think Like a Programmer* (V. Anton Spraul) — Problem-solving
- *The Programmer's Brain* (Felienne Hermans) — Cognitive processes
- Big-O Notation and Radix Sort (Wikipedia)

### AI Usage

AI was used to assist with the following tasks:

- **Scaffolding:** initial directory structure and Makefile rules.
- **Data structures:** definition of `t_number` and `t_bench` structs.
- **Logic:** assistance with the `compute_disorder` mathematical formula and `ft_atol` validation.

All code was manually reviewed, refactored for Norm compliance, and tested to ensure full understanding.

---

## Contributions

Both members contributed equally to the core logic.

| Member       | Responsibilities                                         |
|--------------|------------------------------------------------------------|
| **jamsilva** | Parsing, validation, and Simple/Medium algorithms           |
| **luafranc** | Operations base, Radix implementation, and Adaptive logic   |
