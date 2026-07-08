# Libft

## Description

Libft is the first foundational project of the 42 curriculum. Its purpose is to recreate essential functions from the standard C library while developing a deeper understanding of memory management, pointers, data structures, and low-level programming concepts.

The project consists of building a custom static library named `libft.a`, which can be reused throughout future 42 projects.

Through this project, I learned how standard library functions work internally and gained practical experience with manual memory management, defensive programming, and software modularization.

---

## Project Overview

The library contains:

* Reimplemented libc functions
* Memory manipulation utilities
* String manipulation functions
* Conversion functions
* File descriptor output functions
* Linked list management utilities

All functions were implemented following the 42 Norm and compiled with:

```bash
-Wall -Wextra -Werror
```

---

## Features

* Custom implementation of standard C library functions
* Safe memory allocation and manipulationarticles
* String processing utilities
* Integer and character conversion utilities
* File descriptor output functions
* Singly linked list implementation
* Modular and reusable architecture
* Norm-compliant source code

---

## Library Description

`libft.a` is a static library designed to provide reusable utility functions for future projects.

### Character Functions

| Function     | Description                            |
| ------------ | -------------------------------------- |
| `ft_isalpha` | Checks if a character is alphabetic    |
| `ft_isdigit` | Checks if a character is a digit       |
| `ft_isalnum` | Checks if a character is alphanumeric  |
| `ft_isascii` | Checks if a character belongs to ASCII |
| `ft_isprint` | Checks if a character is printable     |
| `ft_toupper` | Converts a character to uppercase      |
| `ft_tolower` | Converts a character to lowercase      |

### String Functions

| Function      | Description                             |
| ------------- | --------------------------------------- |
| `ft_strlen`   | Returns string length                   |
| `ft_strchr`   | Finds first occurrence of a character   |
| `ft_strrchr`  | Finds last occurrence of a character    |
| `ft_strncmp`  | Compares strings                        |
| `ft_strnstr`  | Searches a string inside another string |
| `ft_strdup`   | Duplicates a string                     |
| `ft_substr`   | Extracts a substring                    |
| `ft_strjoin`  | Concatenates two strings                |
| `ft_strtrim`  | Removes characters from both ends       |
| `ft_split`    | Splits a string into substrings         |
| `ft_strmapi`  | Applies a function to each character    |
| `ft_striteri` | Iterates through a string               |

### Memory Functions

| Function     | Description                       |
| ------------ | --------------------------------- |
| `ft_memset`  | Fills memory with a constant byte |
| `ft_bzero`   | Sets memory to zero               |
| `ft_memcpy`  | Copies memory                     |
| `ft_memmove` | Copies overlapping memory safely  |
| `ft_memchr`  | Searches memory                   |
| `ft_memcmp`  | Compares memory blocks            |
| `ft_calloc`  | Allocates and initializes memory  |

### Conversion Functions

| Function  | Description                |
| --------- | -------------------------- |
| `ft_atoi` | Converts string to integer |
| `ft_itoa` | Converts integer to string |

### File Descriptor Functions

| Function        | Description                             |
| --------------- | --------------------------------------- |
| `ft_putchar_fd` | Writes a character to a file descriptor |
| `ft_putstr_fd`  | Writes a string to a file descriptor    |
| `ft_putendl_fd` | Writes a string followed by a newline   |
| `ft_putnbr_fd`  | Writes a number to a file descriptor    |

### Linked List Functions

| Function          | Description                      |
| ----------------- | -------------------------------- |
| `ft_lstnew`       | Creates a new node               |
| `ft_lstadd_front` | Adds a node at the beginning     |
| `ft_lstsize`      | Counts nodes in a list           |
| `ft_lstlast`      | Returns the last node            |
| `ft_lstadd_back`  | Adds a node at the end           |
| `ft_lstdelone`    | Deletes a single node            |
| `ft_lstclear`     | Deletes an entire list           |
| `ft_lstiter`      | Applies a function to every node |
| `ft_lstmap`       | Creates a new transformed list   |

---

## Instructions

### Requirements

* GCC or Clang
* Make
* Linux or macOS

### Compile

```bash
make
```

This generates:

```bash
libft.a
```

### Clean Object Files

```bash
make clean
```

### Remove All Generated Files

```bash
make fclean
```

### Rebuild Everything

```bash
make re
```

---

## Usage

Include the header:

```c
#include "libft.h"
```

Compile your project with the library:

```bash
gcc main.c libft.a
```

or

```bash
gcc main.c -L. -lft
```

---

## Technical Choices

Some implementation decisions made during the project:

* Static library architecture
* Modular source code organization
* Defensive memory allocation checks
* Reusable helper functions
* Linked list abstraction through generic `void *` content
* Strict compliance with the 42 Norm

---

## Testing

The project was validated using:

* Custom test cases
* Edge case testing
* Norminette
* Valgrind memory analysis

Example:

```bash
valgrind --leak-check=full ./program
```

---

## Resources

### Documentation

* The C Programming Language — Brian W. Kernighan & Dennis M. Ritchie
* Linux Manual Pages (`man`)
* POSIX Documentation
* GNU C Documentation
* 42 Subject PDF

### References

* https://man7.org/linux/man-pages/
* https://cplusplus.com/
* https://developer.mozilla.org/
* https://www.geeksforgeeks.org/c-programming-language/

### AI Usage

Artificial Intelligence tools were used as learning assistants for:

* Concept clarification
* Documentation support
* Debugging guidance
* Understanding edge cases
* Code review suggestions

All implementations, testing, debugging, and final validation were completed manually by the author.

---

## What I Learned

This project strengthened my understanding of:

* Memory allocation and deallocation
* Pointer arithmetic
* String manipulation
* Static libraries
* Linked lists
* Defensive programming
* UNIX development workflows
* Writing reusable C code

---

## Author

Jamielly R.
GitHub: https://github.com/Jamielly
