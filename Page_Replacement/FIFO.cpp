#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, capacity;
    cout << "Enter number of pages: ";
    cin >> n;
    
    vector<int> pages(n);
    cout << "Enter page reference string: ";
    for(int i=0; i<n; i++) {
        cin >> pages[i];
    }
    
    cout << "Enter number of frames: ";
    cin >> capacity;
    
    vector<int> frames;
    int pageFaults = 0;
    
    for(int i=0; i<n; i++) {
        int page = pages[i];
        bool found = false;
        
        for(int x : frames) {
            if(x == page) {
                found = true;
                break;
            }
        }
        
        if(!found) {
            if(frames.size() < capacity) {
                frames.push_back(page);
            } else {
                // FIFO logic: Replace the first one (0th index)
                frames.erase(frames.begin());
                frames.push_back(page);
            }
            pageFaults++;
        }
        
        // Print current frames
        cout << "Page " << page << ": ";
        for(int x : frames) cout << x << " ";
        cout << endl;
    }
    
    cout << "\nTotal Page Faults: " << pageFaults << endl;
    
    return 0;
}
