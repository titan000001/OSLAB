# Preemptive Priority Scheduling Algorithm Explanation

## Code Overview
This C++ program implements the **Preemptive Priority Scheduling** algorithm. In this algorithm, the CPU is assigned to the process with the highest priority (lowest numerical value) among the available processes. If a new process arrives with a higher priority than the currently running process, the CPU is preempted (taken away) and assigned to the new process.

## Step-by-Step Execution

1.  **Header Files and Structure Definition**:
    -   Libraries like `iostream`, `vector`, and `algorithm` are included.
    -   A `struct Process` is defined to hold process details: ID, Arrival Time (AT), Burst Time (BT), Priority, Remaining BT, Completion Time (CT), Turnaround Time (TAT), Waiting Time (WT), and a completion flag.

2.  **Input Phase**:
    -   The user inputs the number of processes.
    -   For each process, the `Arrival Time`, `Burst Time`, and `Priority` are entered.
    -   `remaining_burst_time` is initialized to the `burst_time`.

3.  **Simulation Loop**:
    -   The core logic is a `while` loop that runs until `completed_processes_count` equals the total number of processes.
    -   Inside the loop (`current_time` keeps increasing):
        -   **Selection**: It iterates through all processes to find a process that:
            -   Has arrived (`arrival_time <= current_time`).
            -   Is not yet completed.
            -   Has the **highest priority** (lowest integer value).
        -   **Execution**:
            -   If such a process is found, it runs for **1 unit of time** (`remaining_burst_time--`).
            -   `current_time` is incremented.
        -   **Completion Check**:
            -   If `remaining_burst_time` becomes 0, the process is marked completed.
            -   **Calculations**:
                -   `Completion Time (CT)` = `current_time`
                -   `Turnaround Time (TAT)` = `CT` - `Arrival Time`
                -   `Waiting Time (WT)` = `TAT` - `Original Burst Time`
        -   **Idle Time**: If no process is available to run, `current_time` is just incremented.

4.  **Output**:
    -   The program prints a table showing AT, BT, Priority, CT, TAT, and WT for each process.
    -   It calculates and prints the **Average Turnaround Time** and **Average Waiting Time**.
