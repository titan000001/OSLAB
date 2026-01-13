# Round Robin (RR) Scheduling Algorithm Explanation

## Code Overview
This program implements the **Round Robin (RR)** scheduling algorithm. It is a preemptive algorithm where each process is assigned a fixed time slot (Time Quantum) in a cyclic order. It is designed to give better response time for time-sharing systems.

## Step-by-Step Execution

1.  **Structure and Setup**:
    -   Uses `struct Process` to store process attributes.
    -   Defines a comparator `compareAT` to sort processes by Arrival Time.

2.  **Input**:
    -   Reads the number of processes and the **Time Quantum**.
    -   Reads Arrival Time (AT) and Burst Time (BT) for each process.
    -   `remaining_burst_time` is set to `BT`.

3.  **Initialization**:
    -   Sorts the processes based on Arrival Time.
    -   Uses a `vector<int> ready_queue` to manage the execution order.
    -   Initially pushes the first arriving process into the `ready_queue`.

4.  **Scheduling Loop**:
    -   The loop runs while `completed_processes_count` < total processes.
    -   **Queue Management**:
        -   It takes the first process from the `ready_queue`.
    -   **Execution**:
        -   The process runs for a time `t` which is the minimum of `time_quantum` or `remaining_burst_time`.
        -   `remaining_burst_time` is reduced by `t`.
        -   Current time advances by `t`.
    -   **New Arrivals**:
        -   The code checks for any new processes that have arrived during this time interval `t`.
        -   Newly arrived processes are pushed to the back of the `ready_queue`.
    -   **Re-queuing**:
        -   If the current process still has remaining time, it is pushed back to the `ready_queue` (Context Switch).
        -   If it is finished (`remaining == 0`), completion stats (CT, TAT, WT) are calculated.
    -   **Idle Handling**:
        -   If the queue is empty but processes are left, the time is incremented to the next process's arrival.

5.  **Output**:
    -   Displays the schedule details (CT, TAT, WT) for each process.
    -   Computes and prints average TAT and WT.
