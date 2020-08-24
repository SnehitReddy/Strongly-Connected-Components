# Strongly Connected Components in a Graph

## Divide and Conquer Algorithm

An implementation of [Algo name given in paper] in [paper link]. Includes an option to write intermediate results of the algorithm to a file for visualization. It differs from the paper in that instead of recursively calling the function for each partition, it stores partitions to be processed in a queue and processes items until queue is empty. This avoids the need to allot more stack space for large graphs.

#### Improvements
Algorithm can be parallelized

#### Issues Faced
Recursive implementation of the algorithm required a very large stack size. Iteration uses heap but will still require a lot of memory for large graphs.
