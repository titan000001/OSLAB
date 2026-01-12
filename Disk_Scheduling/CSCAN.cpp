#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int number_of_requests, initial_head_position, disk_track_limit;
    cout << "Enter number of requests: ";
    cin >> number_of_requests;
    
    vector<int> request_queue(number_of_requests);
    cout << "Enter the requests sequence: ";
    for(int i=0; i<number_of_requests; i++) {
        cin >> request_queue[i];
    }
    
    cout << "Enter initial head position: ";
    cin >> initial_head_position;
    cout << "Enter disk size (max cylinders): ";
    cin >> disk_track_limit;
    
    sort(request_queue.begin(), request_queue.end());
    
    int total_seek_time = 0;
    int current_track_position = initial_head_position;
    
    vector<int> left_requests, right_requests;
    
    for(int i=0; i<number_of_requests; i++) {
        if(request_queue[i] < initial_head_position) left_requests.push_back(request_queue[i]);
        else right_requests.push_back(request_queue[i]);
    }
    
    cout << "Seek Sequence: " << initial_head_position;
    
    // Move Right
    for(int i=0; i<right_requests.size(); i++) {
        total_seek_time += abs(right_requests[i] - current_track_position);
        current_track_position = right_requests[i];
        cout << " -> " << current_track_position;
    }
    
    // Go to end
    if(current_track_position != disk_track_limit - 1) {
        total_seek_time += abs((disk_track_limit - 1) - current_track_position);
        current_track_position = disk_track_limit - 1;
        cout << " -> " << current_track_position;
    }
    
    // Jump to beginning (0) - This jump counts according to some definitions, or not.
    // Usually CSCAN counts the jump as seek time too, though sometimes treated as 0 overhead.
    // Standard algorithm: Head -> End -> 0 -> Left part
    
    total_seek_time += abs(0 - current_track_position);
    current_track_position = 0;
    cout << " -> " << current_track_position;
    
    // Now visit left part from 0 upwards
    for(int i=0; i<left_requests.size(); i++) {
        total_seek_time += abs(left_requests[i] - current_track_position);
        current_track_position = left_requests[i];
        cout << " -> " << current_track_position;
    }
    
    cout << "\nTotal Seek Time: " << total_seek_time << endl;
    
    return 0;
}
