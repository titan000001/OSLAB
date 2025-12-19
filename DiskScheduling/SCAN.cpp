#include <iostream>
#include <algorithm> 
#include <functional> 

using namespace std;

const int DISK_SIZE = 200; 

void scan_down(const int initial_queue[], int queue_size, int initial_head) {
    int current_head = initial_head;
    int total_seek_time = 0;
    
    int seek_sequence[queue_size + 3]; 
    int sequence_index = 0; 

    int lower[queue_size]; 
    int upper[queue_size]; 
    int lower_count = 0;
    int upper_count = 0;

    for (int i = 0; i < queue_size; ++i) {
        if (initial_queue[i] < initial_head) {
            lower[lower_count++] = initial_queue[i];
        } else {
            upper[upper_count++] = initial_queue[i]; 
        }
    }

    sort(lower, lower + lower_count, greater<int>());
    sort(upper, upper + upper_count);  

    seek_sequence[sequence_index++] = initial_head;

    for (int i = 0; i < lower_count; ++i) {
        int seek_time = lower[i] - current_head;
        if (seek_time < 0) {
            seek_time = -seek_time;
        }

        total_seek_time += seek_time;
        current_head = lower[i];
        seek_sequence[sequence_index++] = current_head;
    }
    
    if (current_head != 0) {
        int seek_to_end = 0 - current_head;
        if (seek_to_end < 0) seek_to_end = -seek_to_end;

        total_seek_time += seek_to_end;
        current_head = 0;
        seek_sequence[sequence_index++] = current_head; 
    }

    for (int i = 0; i < upper_count; ++i) {
        int seek_time = upper[i] - current_head;
        if (seek_time < 0) {
            seek_time = -seek_time;
        }

        total_seek_time += seek_time;
        current_head = upper[i];
        seek_sequence[sequence_index++] = current_head;
    }
    
    cout << "--- SCAN Disk Scheduling Algorithm (Initial Direction DOWN) ---" << endl;
    cout << "Initial Head Position: " << initial_head << endl;
    cout << "Disk size assumed from 0 to " << DISK_SIZE - 1 << endl;
    cout << "Initial Direction: DOWN (towards 0)" << endl;
    cout << "Request Queue: ";
    for (int k = 0; k < queue_size; ++k) {
        cout << initial_queue[k] << " ";
    }
    
    cout << "\n\nSeek Sequence:" << endl;
    for (int k = 0; k < sequence_index; ++k) {
        cout << seek_sequence[k];
        if (k < sequence_index - 1) {
            cout << " -> ";
        }
    }
    cout << "\n\nTotal Seek Time: " << total_seek_time << endl;
}

int main() {
    const int request_queue[] = {98, 183, 37, 122, 14, 124, 65, 67};
    const int N = sizeof(request_queue) / sizeof(request_queue[0]);
    int initial_head = 53;

    scan_down(request_queue, N, initial_head);

    return 0;
}
