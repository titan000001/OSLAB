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
                // Optimal replacement: Find page that will not be used for longest time
                int farthest_next_use_index = -1;
                int index_to_replace = -1;
                
                for(int j=0; j<current_frames.size(); j++) {
                    int next_use_index = -1;
                    for(int k=i+1; k<number_of_pages; k++) {
                        if(page_reference_string[k] == current_frames[j]) {
                            next_use_index = k;
                            break;
                        }
                    }
                    
                    if(next_use_index == -1) {
                        index_to_replace = j;
                        break;
                    } 
                    
                    if(next_use_index > farthest_next_use_index) {
                        farthest_next_use_index = next_use_index;
                        index_to_replace = j;
                    }
                }
                
                if(index_to_replace == -1) index_to_replace = 0; // Should not happen with logic above unless logic flaw, safer default
                current_frames[index_to_replace] = current_page;
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
