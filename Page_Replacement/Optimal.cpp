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
                // Optimal replacement: Find page that will not be used for longest time
                int farthest = -1;
                int idxToReplace = -1;
                
                for(int j=0; j<frames.size(); j++) {
                    int nextUse = -1;
                    for(int k=i+1; k<n; k++) {
                        if(pages[k] == frames[j]) {
                            nextUse = k;
                            break;
                        }
                    }
                    
                    if(nextUse == -1) {
                        idxToReplace = j;
                        break;
                    } 
                    
                    if(nextUse > farthest) {
                        farthest = nextUse;
                        idxToReplace = j;
                    }
                }
                
                if(idxToReplace == -1) idxToReplace = 0; // Should not happen with logic above unless logic flaw, safer default
                frames[idxToReplace] = page;
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
