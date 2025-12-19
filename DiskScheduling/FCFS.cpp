#include <iostream>
#include <cmath>

using namespace std;

void fcfs_disk(const int initial_queue[], int queue_size, int initial_head) {
    int current_head = initial_head;
    int total_seek_time = 0;
    
    cout << "--- FCFS Disk Scheduling Algorithm ---" << endl;
    cout << "Initial Head Position: " << initial_head << endl;
    cout << "Request Queue: ";
    for (int k = 0; k < queue_size; ++k) {
        cout << initial_queue[k] << " ";
    }
    
    cout << "\n\nSeek Sequence:" << endl;
    cout << initial_head;

    for (int i = 0; i < queue_size; ++i) {
        int next_request = initial_queue[i];
        int seek_time = next_request - current_head;
        if (seek_time < 0) {
            seek_time = -seek_time;
        }

        total_seek_time += seek_time;
        current_head = next_request;

        cout << " -> " << current_head;
    }
    
    cout << "\n\nTotal Seek Time: " << total_seek_time << endl;
}

int main() {
    int request_queue[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int N = sizeof(request_queue) / sizeof(request_queue[0]);
    int initial_head = 53;

    fcfs_disk(request_queue, N, initial_head);

    return 0;
}
