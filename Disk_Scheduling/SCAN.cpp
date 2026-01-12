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
    
    // Sort requests
    sort(requests.begin(), requests.end());
    
    int total_seek_time = 0;
    int current = head;
    
    // Assuming moving towards higher values (Right)
    vector<int> left, right;
    
    for(int i=0; i<n; i++) {
        if(requests[i] < head) left.push_back(requests[i]);
        else right.push_back(requests[i]);
    }
    
    // Logic: Head -> Max -> Leftmost
    // SCAN visits the ends.
    // Moving Right:
    
    cout << "Seek Sequence: " << head;
    
    // Visit right
    for(int i=0; i<right.size(); i++) {
        total_seek_time += abs(right[i] - current);
        current = right[i];
        cout << " -> " << current;
    }
    
    // Continue to end if needed (usually SCAN goes to end)
    if(right.size() > 0 && current != disk_size - 1) { // Standard SCAN hits boundary
         total_seek_time += abs((disk_size - 1) - current);
         current = disk_size - 1;
         cout << " -> " << current;
    } else if (right.empty()) {
        total_seek_time += abs((disk_size - 1) - current);
        current = disk_size - 1;
        cout << " -> " << current;
    }
    
    // Now reverse to left
    // Left needs to be visited in descending order (closest to current first after reversal)
    for(int i=left.size()-1; i>=0; i--) {
        total_seek_time += abs(left[i] - current);
        current = left[i];
        cout << " -> " << current;
    }
    
    cout << "\nTotal Seek Time: " << total_seek_time << endl;
    
    return 0;
}
