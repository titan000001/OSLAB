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
        
        for(int x : current_frames) {
            if(x == current_page) {
                is_page_in_frames = true;
                break;
            }
        }
        
        if(!is_page_in_frames) {
            if(current_frames.size() < frame_capacity) {
                current_frames.push_back(current_page);
            } else {
                // FIFO logic: Replace the first one (0th index)
                current_frames.erase(current_frames.begin());
                current_frames.push_back(current_page);
            }
            total_page_faults++;
        }
        
        // Print current frames
        cout << "Page " << current_page << ": ";
        for(int x : current_frames) cout << x << " ";
        cout << endl;
    }
    
    cout << "\nTotal Page Faults: " << total_page_faults << endl;
    
    return 0;
}
