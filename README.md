
# 0x1B. C - Sorting algorithms & Big O

# Sorting Algorithms Project

## Overview

This project focuses on implementing and understanding various sorting algorithms, Big O notation, and selecting the best sorting algorithm for a given input. Additionally, it covers the concept of stable sorting algorithms and includes guidelines and requirements for implementation.

## Learning Objectives

- Implement at least four different sorting algorithms.
- Understand the Big O notation and how to evaluate the time complexity of an algorithm.
- Learn how to select the best sorting algorithm for a given input.
- Understand the concept of a stable sorting algorithm.
- Emphasize the importance of avoiding plagiarism and following project requirements.

## Requirements

### General

- Allowed editors: vi, vim, emacs.
- Compilation on Ubuntu 20.04 LTS using gcc with specific options.
- All files should end with a new line.
- Mandatory README.md file at the root of the project folder.
- Code should adhere to the Betty style.
- Avoid using global variables.
- Limit each file to no more than 5 functions.
- Unless specified otherwise, do not use the standard library functions like printf, puts, etc.
- Prototypes of all functions should be included in the header file (sort.h).
- Header files should be include guarded.
- List/array doesn't need sorting if its size is less than 2.

### GitHub

- One project repository per group.
- Avoid cloning/forking a project repository with the same name before the second deadline to prevent a 0% score.

## Data Structure and Functions

### Functions

```c
#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;
```
### Big O Notation
- O(1)
- O(n)
- O(n!)
- O(n^2)
- O(log(n))
- O(n * log(n))
- O(n + k)
Use the short notation (without constants).
