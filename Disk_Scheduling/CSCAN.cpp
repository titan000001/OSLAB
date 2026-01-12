#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, head, disk_size;
    cout << "Enter number of requests: ";
    cin >> n;
    
    vector<int> requests(n);
    cout << "Enter the requests sequence: ";
    for(int i=0; i<n; i++) {
        cin >> requests[i];
    }
    
    cout << "Enter initial head position: ";
    cin >> head;
    cout << "Enter disk size (max cylinders): ";
    cin >> disk_size;
    
    sort(requests.begin(), requests.end());
    
    int total_seek_time = 0;
    int current = head;
    
    vector<int> left, right;
    
    for(int i=0; i<n; i++) {
        if(requests[i] < head) left.push_back(requests[i]);
        else right.push_back(requests[i]);
    }
    
    cout << "Seek Sequence: " << head;
    
    // Move Right
    for(int i=0; i<right.size(); i++) {
        total_seek_time += abs(right[i] - current);
        current = right[i];
        cout << " -> " << current;
    }
    
    // Go to end
    if(current != disk_size - 1) {
        total_seek_time += abs((disk_size - 1) - current);
        current = disk_size - 1;
        cout << " -> " << current;
    }
    
    // Jump to beginning (0) - This jump counts according to some definitions, or not.
    // Usually CSCAN counts the jump as seek time too, though sometimes treated as 0 overhead.
    // Standard algorithm: Head -> End -> 0 -> Left part
    
    total_seek_time += abs(0 - current);
    current = 0;
    cout << " -> " << current;
    
    // Now visit left part from 0 upwards
    for(int i=0; i<left.size(); i++) {
        total_seek_time += abs(left[i] - current);
        current = left[i];
        cout << " -> " << current;
    }
    
    cout << "\nTotal Seek Time: " << total_seek_time << endl;
    
    return 0;
}
