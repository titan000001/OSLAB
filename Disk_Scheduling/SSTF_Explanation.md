# Shortest Seek Time First (SSTF) Explanation

## Code Overview
This program implements the **Shortest Seek Time First (SSTF)** disk scheduling algorithm. It selects the request with the minimum seek time from the current head position. It is a greedy algorithm.

## Step-by-Step Execution

1.  **Input**:
    -   Number of requests, Sequence, Initial Head.
    -   A boolean vector `is_request_processed` tracks completed requests.

2.  **Simulation Loop**:
    -   Runs until `completed_requests_count` equals total requests.
    -   **Find Closest Request**:
        -   In each iteration, it scans **all** unvisited requests.
        -   It calculates the distance (`abs(request - current)`) for each.
        -   It identifies the request with the **minimum distance**.
    -   **Execute**:
        -   The closest request is marked as processed.
        -   `total_seek_time` is incremented by the minimum distance.
        -   `current_track_position` becomes the selected request's track.

3.  **Result**:
    -   Since it always picks the closest one, the sequence jumps around based on locality, potentially causing starvation for distant requests (though valid for minimizing immediate seek).
    -   Prints Sequence and Total Seek Time.
