# Shortest Remaining Time First (SRTF) Explanation

## Code Overview
This code implements **Shortest Remaining Time First (SRTF)**, which is the preemptive version of the Shortest Job First (SJF) algorithm. At any unit of time, the processor is allocated to the process with the least amount of remaining burst time.

## Step-by-Step Execution

1.  **Data Structure**:
    -   Standard `struct Process` holds ID, AT, BT, Remaining Time, etc.

2.  **Input**:
    -   User enters the number of processes.
    -   Loops to accept Arrival Time and Burst Time for every process.
    -   Initializes `remaining_burst_time` with the initial `burst_time`.

3.  **Core Logic (Simulation Loop)**:
    -   A `while` loop continues until all processes are completed.
    -   **Selection Strategy (Greedy)**:
        -   At every time step (`current_time` increments by 1), the scheduler scans all available processes (Arrived & Not Completed).
        -   It selects the process with the **minimum `remaining_burst_time`**.
    -   **Execution**:
        -   The selected process runs for 1 unit of time.
        -   `remaining_burst_time` is decremented.
    -   **Completion**:
        -   If `remaining_burst_time` hits 0:
            -   `Completion Time` = current time.
            -   `Turnaround Time` = CT - Arrival Time.
            -   `Waiting Time` = TAT - Burst Time.
            -   Process is marked as completed.
    
4.  **Result Display**:
    -   A table is printed with all calculated timings.
    -   Average Turnaround and Waiting times are displayed.

5.  **Key Feature**:
    -   If a short process arrives while a long process is running, SRTF will switch to the new short process immediately (Preemption).
