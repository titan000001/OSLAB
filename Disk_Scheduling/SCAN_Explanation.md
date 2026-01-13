# SCAN Disk Scheduling Explanation

## Code Overview
This program implements the **SCAN (Elevator)** disk scheduling algorithm. The disk arm starts from one end of the disk and moves towards the other end, servicing requests along the way. When it reaches the other end, the direction of head movement is reversed, and servicing continues.

## Step-by-Step Execution

1.  **Input**:
    -   Number of requests, Sequence, Initial Head, and **Disk Track Limit**.

2.  **Sorting & Splitting**:
    -   Requests are sorted.
    -   Split into `left_requests` (< Head) and `right_requests` (> Head).

3.  **Direction Assumption**:
    -   This specific code assumes the initial direction is **Right** (towards higher values).

4.  **Simulation**:
    -   **Move Right**:
        -   Service all `right_requests`.
    -   **Hit Boundary**:
        -   The head continues to the end of the disk (`disk_track_limit - 1`).
        -   This extra move is added to seek time.
    -   **Reverse Direction (Move Left)**:
        -   The head now moves from the end towards the beginning.
        -   It services `left_requests` in **descending order** (reverse iteration), as those are closest to the end now.

5.  **Output**:
    -   Prints the zigzag Sequence.
    -   Prints Total Seek Time.
