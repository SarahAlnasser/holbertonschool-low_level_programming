# Green Efficiency Analysis

## Measurement Methodology

All three programs were compiled with `gcc -Wall -Werror -Wextra -pedantic -std=gnu99` and no optimization flag, so the compiler kept the loops as written. Each program was run three consecutive times on the same machine. Timing uses `clock()` from `<time.h>`, which measures processor time consumed by the process, converted to seconds by dividing by `CLOCKS_PER_SEC` and printed with `%.6f`.

For `instrumentation_lab.c`, a `clock()` call was placed immediately before and after each phase function (`build_dataset`, `process_dataset`, `reduce_checksum`). TOTAL starts just before the build phase and ends just after the reduce phase, so it covers the same region as the three phases combined. The algorithmic logic was not changed.

## Observed Performance Differences

The baseline loop of 100,000,000 iterations took 0.083500 s, 0.050067 s and 0.050272 s, an average of 0.061280 s. The program is deterministic, yet the slowest and fastest runs differ by 0.033433 s, about 55% of the average. Identical work does not produce identical timings, so repeated runs are needed.

The algorithm comparison shows a much larger effect. The naive version averaged 0.764734 s (0.777689, 0.759715, 0.756797), while the single-pass version averaged 0.000030 s (0.000032, 0.000028, 0.000031). The naive implementation is about 25211 times slower. This matches their complexity: the naive version performs about 1.25 billion inner iterations, while the single-pass version performs 50,000.

In the instrumentation lab (three runs), TOTAL averaged 0.000873 s. BUILD_DATA averaged 0.000289 s (about 33% of TOTAL), PROCESS 0.000382 s (about 44%) and REDUCE 0.000196 s (about 22%). The three phases sum to 0.000867 s, close to TOTAL, so the chosen boundaries account for nearly all measured time. PROCESS was the most expensive phase at about 44% of TOTAL.

## Relation Between Runtime and Energy Consumption

`clock()` reports CPU time, which is time the processor spends actively working for the program. A busy processor draws power, so on the same machine and workload, energy is roughly proportional to power multiplied by CPU time. Under that assumption, the naive algorithm, which used about 25211 times more CPU time than the single-pass version to scan the same 50,000 integers, would consume roughly that much more energy. The baseline runs show the same relation on a smaller scale: the slowest run (0.083500 s) kept the CPU busy about 67% longer than the fastest run (0.050067 s). Power was not measured directly, so this is an estimate based on runtime, not a measured energy value.

## Limitations of the Experiment

- Only three runs per program were recorded, and the baseline varied by about 55% between runs, so the averages carry real uncertainty.
- The instrumentation phases last only microseconds to fractions of a millisecond. That is close to the resolution of `clock()`, so the phase percentages are approximate.
- Energy was not measured with a power meter or hardware counters such as RAPL. The energy discussion assumes constant processor power, which ignores frequency scaling, turbo boost and idle states.
- Results come from one machine, with other processes running in the background, and without compiler optimization. Different hardware or `-O2` would give different absolute times.
- The two comparison algorithms return different results (625025000 versus 25000), so they are not strictly equivalent computations, even though both iterate over the same data.

## Practical Engineering Takeaway

The algorithm mattered far more than anything else measured. Choosing an O(n) approach instead of an O(n²) one reduced runtime from 0.764734 s to 0.000030 s, while run-to-run noise in the baseline was only 0.033433 s. To reduce energy use, the first step is to fix algorithmic complexity, then profile phases to find where time goes, as the instrumentation showed with PROCESS taking about 44% of the total. Measurements should always be repeated and averaged, because a deterministic program still produced different timings across runs.
