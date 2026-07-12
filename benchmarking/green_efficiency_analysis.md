Green Efficiency Analysis

Measurement Methodology

To establish a rigorous baseline and conduct a fair algorithmic comparison, all experiments were executed in a controlled, isolated local environment. The benchmarking suite leveraged the standard C library <time.h> and utilised the clock() function to track CPU time slices allocated to the processes. To ensure measurement integrity, the source code was compiled under strict GNU89 standards using the required compiler configuration: gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long.

The measurement boundaries for the multi-phase instrumentation experiment were established by placing clock() calls immediately before and after the invocation of each sub-routine (build_dataset, process_dataset, and reduce_checksum). A macro-level timer wrapped all three phases consecutively to capture the continuous execution window. The raw clock ticks were subsequently converted into seconds by dividing the differences by the CLOCKS_PER_SEC constant, ensuring that overhead from standard output operations did not pollute the computational metrics.

Observed Performance Differences

The empirical results revealed massive gaps between the architectural design choices of the algorithms. In Task 0, the deterministic baseline loop, operating over $100,000,000$ iterations, exhibited highly stable timing metrics across consecutive runs, yielding execution times of $0.134618$ seconds, $0.124270$ seconds, and $0.126382$ seconds. This small margin of variance underscores the inherent noise caused by OS thread scheduling.

The most dramatic performance disparity occurred during Task 1, where two distinct strategies competed to filter even numbers from a static array of $50,000$ elements. The Naive algorithm, burdened by a nested-loop structure that yields quadratic time complexity of $O(N^2)$, produced an average execution time of $1.385421$ seconds. Conversely, the optimised Single-pass algorithm, which operates in linear $O(N)$ time, processed the identical dataset in an average of $0.000037$ seconds. Mathematical analysis of these results proves that the Naive implementation is approximately $37,443$ times slower than the Single-pass alternative under identical conditions, providing a clear demonstration of how asymptotic complexity manifests in physical computing environments.

Relation Between Runtime and Energy Consumption

Software runtime can serve as a useful proxy for overall electrical energy consumption at scale. Modern central processing units (CPUs) draw a continuous dynamic power load while actively handling instructions. The total energy ($E$) consumed by a computational workload is defined by the mathematical relationship where energy equals the product of power ($P$) and time ($T$).

Because the Naive algorithm required $1.385421$ seconds to complete, compared to the Single-pass runtime of $0.000037$ seconds, it kept the CPU cores in a high-frequency power state for a vastly longer duration. Operating a program that is more than $37,000$ times slower may mean that the infrastructure's cooling and the processor's silicon draw sustained power to compute identical logical outcomes. In large-scale cloud data centres, scaling such inefficient $O(N^2)$ software loops across millions of daily requests can drastically increase the carbon footprint, compounding hardware degradation and thermal release. Green software engineering relies heavily on minimising these active CPU cycles.

Limitations of the Experiment

While the collected data provides definitive performance insights, the experimental scope contains distinct limitations:

1. The clock() function measures CPU time rather than absolute wall-clock time; it fails to account for external environmental overhead, system interrupts, or I/O blocking.
2. The project relies on execution time as an indirect proxy and does not utilise hardware-level power profiling tools (such as Intel RAPL or specialised digital voltmeters) to sample actual dynamic power draw in watts.
3. The dataset size ($50,000$ elements) is relatively small and fits entirely within the processor’s high-speed L1/L2 hardware caches, meaning the metrics do not reflect the real-world performance degradations associated with main memory (RAM) latency or cache thrashing.

Practical Engineering Takeaway

The primary takeaway from this project is that algorithmic optimisation is an indispensable pillar of sustainable engineering. Micro-optimisations at the compiler level cannot compensate for poor architectural choices; an inefficient $O(N^2)$ algorithmic foundation will inherently waste energy regardless of hardware speed. Responsible developers must treat computational efficiency not merely as a minor speed preference, but as an ecological obligation. The takeaway is clear: write clean, linear-time code to reduce hardware energy consumption and minimise carbon emissions at the source.