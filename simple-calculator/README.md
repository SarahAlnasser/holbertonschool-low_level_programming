# C - Simple Calculator

A menu-driven calculator written in C (`calculator.c`).

## Compile and run

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 calculator.c -o calculator
./calculator
```

## Menu

| Choice | Operation |
|---|---|
| 1 | Add (A + B) |
| 2 | Subtract (A - B) |
| 3 | Multiply (A * B) |
| 4 | Divide (A / B) |
| 0 | Quit (prints `Bye!`) |

Any other number prints `Invalid choice` and the menu is shown again.

## Number type: decimals

The calculator uses **decimals (`double`) for all operations**, so the
behavior is the same for every operation and division is exact:
`10 / 4` prints `Result: 2.5`.

Results are printed with `%g`, so whole numbers have no trailing zeros
(`10 + 25` prints `Result: 35`).

## Division by zero

If `B` is `0` on choice `4`, the program prints exactly:

```
Error: division by zero
```
