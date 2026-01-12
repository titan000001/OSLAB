#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    int number_of_requests, initial_head_position;
    cout << "Enter number of requests: ";
    cin >> number_of_requests;
    
    vector<int> request_queue(number_of_requests);
    vector<bool> is_request_processed(number_of_requests, false);
    
    cout << "Enter the requests sequence: ";
    for(int i=0; i<number_of_requests; i++) {
        cin >> request_queue[i];
    }
    
    cout << "Enter initial head position: ";
    cin >> initial_head_position;
    
    int total_seek_time = 0;
    int current_track_position = initial_head_position;
    int completed_requests_count = 0;
    
    cout << "Seek Sequence: " << initial_head_position;
    
    while(completed_requests_count < number_of_requests) {
        int minimum_seek_distance = INT_MAX;
        int closest_request_index = -1;
        
        for(int i=0; i<number_of_requests; i++) {
            if(!is_request_processed[i]) {
                int seek_distance = abs(request_queue[i] - current_track_position);
                if(seek_distance < minimum_seek_distance) {
                    minimum_seek_distance = seek_distance;
                    closest_request_index = i;
                }
            }
        }
        
        if(closest_request_index != -1) {
            is_request_processed[closest_request_index] = true;
            total_seek_time += minimum_seek_distance;
            current_track_position = request_queue[closest_request_index];
            cout << " -> " << current_track_position;
            completed_requests_count++;
        }
    }
    
    cout << "\nTotal Seek Time: " << total_seek_time << endl;
    
    return 0;
}
