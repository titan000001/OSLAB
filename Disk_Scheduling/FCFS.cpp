#include <iostream>
#include <vector>
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
    
    int total_seek_time = 0;
    int current_track_position = initial_head_position;
    
    cout << "Seek Sequence: " << initial_head_position;
    
    for(int i=0; i<number_of_requests; i++) {
        total_seek_time += abs(request_queue[i] - current_track_position);
        current_track_position = request_queue[i];
        cout << " -> " << current_track_position;
    }
    
    cout << "\nTotal Seek Time: " << total_seek_time << endl;
    
    return 0;
}
