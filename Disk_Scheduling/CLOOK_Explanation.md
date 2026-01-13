# C-LOOK Disk Scheduling Explanation

## Code Overview
This program implements the **Circular LOOK (C-LOOK)** disk scheduling algorithm. It is a variant of C-SCAN. In C-LOOK, the disk arm moves in one direction (e.g., Right), servicing requests. When it reaches the last request in that direction, it "jumps" back to the first request in the other direction without servicing any requests in between, and then continues servicing in the same direction. It does not go to the disk end (track limit) like C-SCAN.

## Step-by-Step Execution

1.  **Input**:
    -   Reads number of requests.
    -   Reads the request sequence vector.
    -   Reads the initial head position.

2.  **Sorting**:
    -   Sorts the `request_queue` in ascending order. This helps in easily identifying requests to the left and right of the head.

3.  **Splitting Requests**:
    -   Iterates through the sorted requests.
    -   Requests smaller than `initial_head_position` go to `left_requests`.
    -   Requests larger (or equal) go to `right_requests`.

4.  **Simulation (Move Right Direction)**:
    -   **Right Pass**: The head moves from the current position to each request in `right_requests` sequentially.
    -   For each move, `abs(destination - current)` is added to `total_seek_time`.
    -   Current head is updated.

5.  **Jump Phase (Circular)**:
    -   After finishing `right_requests`, the head "jumps" to the first request in `left_requests` (the smallest value overall).
    -   This jump distance is added to `total_seek_time`.
    -   The head is now at the start of the `left_requests` queue.

6.  **Completion**:
    -   **Left Pass**: The head continues moving right (conceptually, effectively processing the list from start) through the `left_requests`.
    -   Updates `total_seek_time` and head position.

7.  **Output**:
    -   Prints the full "Seek Sequence" (path of the head).
    -   Prints the `Total Seek Time`.
