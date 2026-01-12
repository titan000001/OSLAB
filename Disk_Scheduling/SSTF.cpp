#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    int n, head;
    cout << "Enter number of requests: ";
    cin >> n;
    
    vector<int> requests(n);
    vector<bool> visited(n, false);
    
    cout << "Enter the requests sequence: ";
    for(int i=0; i<n; i++) {
        cin >> requests[i];
    }
    
    cout << "Enter initial head position: ";
    cin >> head;
    
    int total_seek_time = 0;
    int current = head;
    int completed = 0;
    
    cout << "Seek Sequence: " << head;
    
    while(completed < n) {
        int minDist = INT_MAX;
        int idx = -1;
        
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                int dist = abs(requests[i] - current);
                if(dist < minDist) {
                    minDist = dist;
                    idx = i;
                }
            }
        }
        
        if(idx != -1) {
            visited[idx] = true;
            total_seek_time += minDist;
            current = requests[idx];
            cout << " -> " << current;
            completed++;
        }
    }
    
    cout << "\nTotal Seek Time: " << total_seek_time << endl;
    
    return 0;
}
