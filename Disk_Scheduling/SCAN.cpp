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
    
    // Sort requests
    sort(request_queue.begin(), request_queue.end());
    
    int total_seek_time = 0;
    int current_track_position = initial_head_position;
    
    // Assuming moving towards higher values (Right)
    vector<int> left_requests, right_requests;
    
    for(int i=0; i<number_of_requests; i++) {
        if(request_queue[i] < initial_head_position) left_requests.push_back(request_queue[i]);
        else right_requests.push_back(request_queue[i]);
    }
    
    // Logic: Head -> Max -> Leftmost
    // SCAN visits the ends.
    // Moving Right:
    
    cout << "Seek Sequence: " << initial_head_position;
    
    // Visit right
    for(int i=0; i<right_requests.size(); i++) {
        total_seek_time += abs(right_requests[i] - current_track_position);
        current_track_position = right_requests[i];
        cout << " -> " << current_track_position;
    }
    
    // Continue to end if needed (usually SCAN goes to end)
    if(right_requests.size() > 0 && current_track_position != disk_track_limit - 1) { // Standard SCAN hits boundary
         total_seek_time += abs((disk_track_limit - 1) - current_track_position);
         current_track_position = disk_track_limit - 1;
         cout << " -> " << current_track_position;
    } else if (right_requests.empty()) {
        total_seek_time += abs((disk_track_limit - 1) - current_track_position);
        current_track_position = disk_track_limit - 1;
        cout << " -> " << current_track_position;
    }
    
    // Now reverse to left
    // Left needs to be visited in descending order (closest to current first after reversal)
    for(int i=left_requests.size()-1; i>=0; i--) {
        total_seek_time += abs(left_requests[i] - current_track_position);
        current_track_position = left_requests[i];
        cout << " -> " << current_track_position;
    }
    
    cout << "\nTotal Seek Time: " << total_seek_time << endl;
    
    return 0;
}
