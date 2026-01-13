# C-SCAN Disk Scheduling Explanation

## Code Overview
This program implements the **Circular SCAN (C-SCAN)** disk scheduling algorithm. Like C-LOOK, it restricts scanning to one direction. However, unlike C-LOOK, C-SCAN goes all the way to the end of the disk (track limit) before jumping to the beginning (track 0) and starting again.

## Step-by-Step Execution

1.  **Input**:
    -   Number of requests.
    -   Request sequence.
    -   Initial head position.
    -   **Disk Track Limit**: The size of the disk (required to know where the "end" is).

2.  **Sorting**:
    -   The request queue is sorted in ascending order.

3.  **Splitting**:
    -   Requests are split into `left_requests` (< Head) and `right_requests` (> Head).

4.  **Simulation (Move Right)**:
    -   **Service Right**: Visit all requests in `right_requests`. Calculate seek time.
    -   **Hit Boundary**: If the head is not already at the end, it moves to `disk_track_limit - 1`. This travel is added to seek time.

5.  **Circular Jump**:
    -   The head jumps from `disk_track_limit - 1` all the way to `0`.
    -   This large jump is added to the `total_seek_time`.
    -   Current position becomes `0`.

6.  **Service Left (as Right)**:
    -   From `0`, it moves upwards (Right) to visit all requests in `left_requests`.
    -   It stops after the last request in `left_requests`.

7.  **Output**:
    -   Displays the Seek Sequence.
    -   Displays Total Seek Time.
