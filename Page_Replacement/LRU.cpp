#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int number_of_pages, frame_capacity;
    cout << "Enter number of pages: ";
    cin >> number_of_pages;
    
    vector<int> page_reference_string(number_of_pages);
    cout << "Enter page reference string: ";
    for(int i=0; i<number_of_pages; i++) {
        cin >> page_reference_string[i];
    }
    
    cout << "Enter number of frames: ";
    cin >> frame_capacity;
    
    vector<int> current_frames;
    int total_page_faults = 0;
    
    for(int i=0; i<number_of_pages; i++) {
        int current_page = page_reference_string[i];
        bool is_page_in_frames = false;
        
        // Check if page exists
        int page_index_in_frames = -1;
        for(int j=0; j<current_frames.size(); j++) {
            if(current_frames[j] == current_page) {
                is_page_in_frames = true;
                page_index_in_frames = j;
                break;
            }
        }
        
        if(is_page_in_frames) {
            // LRU Logic: Move accessed page to the back (most recently used position)
            // or we track time. Moving to back is simpler for vector.
            current_frames.erase(current_frames.begin() + page_index_in_frames);
            current_frames.push_back(current_page);
        } else {
            if(current_frames.size() < frame_capacity) {
                current_frames.push_back(current_page);
            } else {
                // LRU Logic: Remove the front (least recently used)
                current_frames.erase(current_frames.begin());
                current_frames.push_back(current_page);
            }
            total_page_faults++;
        }
        
        cout << "Page " << current_page << ": ";
        for(int x : current_frames) cout << x << " ";
        cout << endl;
    }
    
    cout << "\nTotal Page Faults: " << total_page_faults << endl;
    
    return 0;
}
