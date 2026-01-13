# Non-Preemptive Priority Scheduling Explanation

## Code Overview
This code implements **Non-Preemptive Priority Scheduling**. Processes are executed based on their priority. The process with the highest priority (lowest numerical value) is executed first. Once a process starts running, it cannot be interrupted. This implementation assumes all processes are available at the start (Arrival Time = 0).

## Step-by-Step Execution

1.  **Input Phase**:
    -   User enters the number of processes.
    -   For each process, the user inputs **Burst Time** and **Priority**.
    -   Lower integer value implies higher priority.

2.  **Sorting (Scheduling Decision)**:
    -   The core logic relies on `std::sort`.
    -   The `comparePriority` function sorts the list of processes in **ascending order of their priority value**.
    -   This effectively schedules higher priority processes (lower values) to the front of the line.

3.  **Execution Simulation**:
    -   The program iterates through the **sorted** list of processes.
    -   Since it's non-preemptive and all arrive at 0:
        -   The first process in the sorted list runs to completion, then the next, and so on.
    -   **Calculations**:
        -   `Completion Time` = Previous `current_time` + `Burst Time`.
        -   `Turnaround Time` = `Completion Time` (since AT=0).
        -   `Waiting Time` = `Turnaround Time` - `Burst Time`.

4.  **Results**:
    -   Prints detailed timing table.
    -   Calculates Averages for TAT and WT.
