# Shortest Job First (SJF) Explanation

## Code Overview
This program implements the **Shortest Job First (SJF)** scheduling algorithm (Non-Preemptive). This strategy selects the waiting process with the smallest execution time to execute next. This implementation simplifies the scenario by assuming all processes are available initially (Arrival Time = 0).

## Step-by-Step Execution

1.  **Input**:
    -   Reads number of processes.
    -   Reads **Burst Time** for each process.

2.  **Sorting (Greedy Approach)**:
    -   The program uses `std::sort` with a custom comparator `compareBT`.
    -   It sorts all processes in **ascending order of their Burst Time**.
    -   This places the shortest jobs at the beginning of the execution queue.

3.  **Processing**:
    -   The processes are executed sequentially in the sorted order.
    -   **Completion Time**: The cumulative sum of burst times.
    -   **Turnaround Time**: Equal to Completion Time (since Arrival Time is 0).
    -   **Waiting Time**: TAT - Burst Time.

4.  **Note on "Non-Preemptive"**:
    -   Once the shortest job starts, it finishes.
    -   Since we sort the entire list at the start, this is valid only because we assume all processes are ready at time 0. If arrival times were different, we would need to check which processes have arrived before selecting the shortest one.

5.  **Output**:
    -   Displays individual process metrics.
    -   Calculates Average TAT and Average WT.
