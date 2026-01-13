# FCFS Disk Scheduling Explanation

## Code Overview
This program implements the **First-Come, First-Served (FCFS)** disk scheduling algorithm. It is the simplest form of disk scheduling where requests are addressed in the order they arrive in the disk queue.

## Step-by-Step Execution

1.  **Input**:
    -   Number of requests.
    -   **Request Sequence**: Stored in a `vector<int>` preserving the input order.
    -   Initial head position.

2.  **Simulation Loop**:
    -   The program iterates through the `request_queue` linearly from index 0 to N-1.
    -   **Calculation**:
        -   For each request, it calculates the distance (`abs(request - current_head)`).
        -   This distance is added to `total_seek_time`.
        -   The `current_track_position` is updated to the requested track.
    -   **Output Construction**:
        -   It prints the path ("-> destination") as it moves.

3.  **Result**:
    -   Prints the final `Total Seek Time`.

4.  **Characteristics**:
    -   No sorting is performed.
    -   Can result in large seek times ("zig-zag" movement) if requests are scattered.
