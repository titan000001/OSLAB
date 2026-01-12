#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int number_of_requests, initial_head_position;
    cout << "Enter number of requests: ";
    cin >> number_of_requests;
    
    vector<int> request_queue(number_of_requests);
    cout << "Enter the requests sequence: ";
    for(int i=0; i<number_of_requests; i++) {
        cin >> request_queue[i];
    }
    
    cout << "Enter initial head position: ";
    cin >> initial_head_position;
    
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
    
    // Jump to lowest request (first in left)
    // CLOOK does not go to end, it jumps from last processed right to first processed in left
    
    if(!left_requests.empty()) {
        total_seek_time += abs(left_requests[0] - current_track_position);
        current_track_position = left_requests[0];
        cout << " -> " << current_track_position;
        
        for(int i=1; i<left_requests.size(); i++) {
            total_seek_time += abs(left_requests[i] - current_track_position);
            current_track_position = left_requests[i];
            cout << " -> " << current_track_position;
        }
    }
    
    cout << "\nTotal Seek Time: " << total_seek_time << endl;
    
    return 0;
}
