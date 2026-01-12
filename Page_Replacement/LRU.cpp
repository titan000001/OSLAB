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
        
        // Check if page exists
        int indexInFrames = -1;
        for(int j=0; j<frames.size(); j++) {
            if(frames[j] == page) {
                found = true;
                indexInFrames = j;
                break;
            }
        }
        
        if(found) {
            // LRU Logic: Move accessed page to the back (most recently used position)
            // or we track time. Moving to back is simpler for vector.
            frames.erase(frames.begin() + indexInFrames);
            frames.push_back(page);
        } else {
            if(frames.size() < capacity) {
                frames.push_back(page);
            } else {
                // LRU Logic: Remove the front (least recently used)
                frames.erase(frames.begin());
                frames.push_back(page);
            }
            pageFaults++;
        }
        
        cout << "Page " << page << ": ";
        for(int x : frames) cout << x << " ";
        cout << endl;
    }
    
    cout << "\nTotal Page Faults: " << pageFaults << endl;
    
    return 0;
}
