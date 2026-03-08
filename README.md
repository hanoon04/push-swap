*This activity has been created as part of
the 42 curriculum by hal-tawa, kabuhamm.*

# push_swap

## Overview
`push_swap` is a 42 project focused on sorting a stack of integers using a limited set of stack operations and producing the smallest reasonable number of moves possible.

This implementation includes multiple sorting approaches and a small benchmark mode to compare behavior depending on the chosen strategy.

## Features
- Parsing and validating input arguments
- Detecting duplicates and invalid values
- Stack indexing for order-based sorting
- Multiple strategies:
  - Small sort
  - Simple sort
  - Medium chunk-based sort
  - Complex radix sort
  - Adaptive strategy
- Optional benchmark mode with disorder, strategy, complexity, total operations, and per-operation counts

## Project Structure
- **Parsing**: reads input, validates numbers, detects duplicates
- **Stack utilities**: node creation, list management, memory cleanup
- **Operations**: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`
- **Sorting**:
  - `sort2` / `sort3`
  - `insertion_sort`
  - `medium_sort`
  - `radix_sort`
  - `adaptive`
- **Benchmark**:
  - disorder calculation
  - selected strategy and complexity display
  - operation counters

## How It Works
1. Parse flags and input values
2. Build stack `a`
3. Assign indexes to values
4. Choose a sorting strategy
5. Execute operations
6. Optionally print benchmark information to `stderr`
7. Free all allocated memory

## Benchmark Mode
When `--bench` is used, the program prints:
- disorder percentage
- strategy name and complexity
- total operations
- count of each operation type

## Example Usage
```bash
./push_swap 3 2 1
./push_swap --bench 3 2 1
./push_swap --medium 5 1 4 2 3
./push_swap --adaptive --bench 5 1 4 2 3
```

## Resources
- Push Swap article: https://medium.com/@ayogun/push-swap-c1f5d2d41e97
- Push Swap video explanation: https://www.youtube.com/watch?v=OaG81sDEpVk
- Insertion Sort reference: https://www.tutorialspoint.com/data_structures_algorithms
- Radix Sort reference: https://www.tutorialspoint.com/data_structures_algorithms/radix_sort_algorithm.htm

## Note About Sources
This project also used a small amount of AI as a supporting source for explanations, organization, and review while developing and documenting the work.