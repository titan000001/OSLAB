#include <iostream>
#include <vector>
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
    
    int total_seek_time = 0;
    int current = head;
    
    cout << "Seek Sequence: " << head;
    
    for(int i=0; i<n; i++) {
        total_seek_time += abs(requests[i] - current);
        current = requests[i];
        cout << " -> " << current;
    }
    
    cout << "\nTotal Seek Time: " << total_seek_time << endl;
    
    return 0;
}
