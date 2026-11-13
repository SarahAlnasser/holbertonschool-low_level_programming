# Comparison Algorithms Metrics

Compiled with: `gcc -Wall -Werror -Wextra -pedantic -std=gnu99 comparison_algorithms.c -o comparison_algorithms`

## Run 1
```
Naive algorithm result: 625025000
Naive algorithm time: 0.777689 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000032 seconds
```

## Run 2
```
Naive algorithm result: 625025000
Naive algorithm time: 0.759715 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000028 seconds
```

## Run 3
```
Naive algorithm result: 625025000
Naive algorithm time: 0.756797 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000031 seconds
```

## Execution Times

| Run | Naive (A) seconds | Single-pass (B) seconds |
|-----|-------------------|-------------------------|
| 1 | 0.777689 | 0.000032 |
| 2 | 0.759715 | 0.000028 |
| 3 | 0.756797 | 0.000031 |
| **Average** | **0.764734** | **0.000030** |

## Relative Difference

Average A / Average B = 0.764734 / 0.000030 = 25211

**Implementation A (naive) is ~25211 times slower than implementation B (single-pass).**
