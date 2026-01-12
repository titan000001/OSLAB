#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, head;
    cout << "Enter number of requests: ";
    cin >> n;
    
    vector<int> requests(n);
    cout << "Enter the requests sequence: ";
    for(int i=0; i<n; i++) {
        cin >> requests[i];
    }
    
    cout << "Enter initial head position: ";
    cin >> head;
    
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
    
    // Jump to lowest request (first in left)
    // CLOOK does not go to end, it jumps from last processed right to first processed in left
    
    if(!left.empty()) {
        total_seek_time += abs(left[0] - current);
        current = left[0];
        cout << " -> " << current;
        
        for(int i=1; i<left.size(); i++) {
            total_seek_time += abs(left[i] - current);
            current = left[i];
            cout << " -> " << current;
        }
    }
    
    cout << "\nTotal Seek Time: " << total_seek_time << endl;
    
    return 0;
}
