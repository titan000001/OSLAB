#include <iostream>
#include <cmath> 

using namespace std;

void sstf_basic(const int initial_queue[], int queue_size, int initial_head) {
    int current_head = initial_head;
    int total_seek_time = 0;
    
    bool serviced[queue_size] = {false}; 
    
    int seek_sequence[queue_size + 1]; 
    seek_sequence[0] = initial_head;
    int sequence_index = 1; 

    for (int i = 0; i < queue_size; ++i) {
        int min_seek = 99999; 
        int next_request_index = -1;

        for (int j = 0; j < queue_size; ++j) {
            if (!serviced[j]) {
                int seek_time = initial_queue[j] - current_head;
                if (seek_time < 0) {
                    seek_time = -seek_time;
                }

                if (seek_time < min_seek) {
                    min_seek = seek_time;
                    next_request_index = j;
                }
            }
        }
        
        if (next_request_index != -1) {
            int next_request = initial_queue[next_request_index];
            
            total_seek_time += min_seek;
            current_head = next_request;

            serviced[next_request_index] = true;
            seek_sequence[sequence_index++] = current_head;
        }
    }

    cout << "--- SSTF Disk Scheduling Algorithm (Basic) ---" << endl;
    cout << "Initial Head Position: " << initial_head << endl;
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
    int request_queue[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int N = sizeof(request_queue) / sizeof(request_queue[0]);
    int initial_head = 53;

    sstf_basic(request_queue, N, initial_head);

    return 0;
}
