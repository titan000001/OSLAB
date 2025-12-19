#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

void look_down(const int initial_queue[], int queue_size, int initial_head) {
    int current_head = initial_head;
    int total_seek_time = 0;
    
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

    cout << "--- LOOK Disk Scheduling Algorithm (Initial Direction DOWN) ---" << endl;
    cout << "Initial Head Position: " << initial_head << endl;
    cout << "Initial Direction: DOWN (towards 0)" << endl;
    cout << "Request Queue: ";
    for (int k = 0; k < queue_size; ++k) {
        cout << initial_queue[k] << " ";
    }
    
    cout << "\n\nSeek Sequence:" << endl;
    cout << initial_head;

    for (int i = 0; i < lower_count; ++i) {
        int seek_time = abs(lower[i] - current_head);
        total_seek_time += seek_time;
        current_head = lower[i];
        cout << " -> " << current_head;
    }

    for (int i = 0; i < upper_count; ++i) {
        int seek_time = abs(upper[i] - current_head);
        total_seek_time += seek_time;
        current_head = upper[i];
        cout << " -> " << current_head;
    }
    
    cout << "\n\nTotal Seek Time: " << total_seek_time << endl;
}

int main() {
    int request_queue[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int N = sizeof(request_queue) / sizeof(request_queue[0]);
    int initial_head = 53;

    look_down(request_queue, N, initial_head);

    return 0;
}
