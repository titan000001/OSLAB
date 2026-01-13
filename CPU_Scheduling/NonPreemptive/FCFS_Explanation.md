# First-Come, First-Served (FCFS) Scheduling Explanation

## Code Overview
This program implements the **First-Come, First-Served (FCFS)** scheduling algorithm. It is the simplest CPU scheduling algorithm which is **non-preemptive**. The process that requests the CPU first is allocated the CPU first. In this specific implementation, it is assumed that **all processes arrive at time 0** (or in the order of input), as there is no user input for Arrival Time.

## Step-by-Step Execution

1.  **Structure Definition**:
    -   A `struct Process` holds:
        -   ID, Burst Time (BT)
        -   Completion Time (CT), Turnaround Time (TAT), Waiting Time (WT).

2.  **Input**:
    -   User enters the number of processes.
    -   User inputs the **Burst Time** for each process sequentially.
    -   The Arrival Time is inherently considered as 0 for the calculations (since TAT = CT).

3.  **Scheduling Calculation**:
    -   The program iterates through the processes in the order they were entered (Linear Loop).
    -   **Current Time Tracking**:
        -   `current_time` starts at 0.
        -   For each process:
            -   `Completion Time` = `current_time` + `Burst Time`.
            -   `current_time` is updated to this new `Completion Time`.
    -   **Metrics Calculation**:
        -   `Turnaround Time (TAT)` = `Completion Time` - `Arrival Time` (where AT=0, so TAT = CT).
        -   `Waiting Time (WT)` = `Turnaround Time` - `Burst Time`.

4.  **Output**:
    -   A table displays the calculated times for each process.
    -   The program computes and prints the **Average Turnaround Time** and **Average Waiting Time**.

5.  **Note**: This is a simplified FCFS where Arrival Time is ignored/assumed 0.
