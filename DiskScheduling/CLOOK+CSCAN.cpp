#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void runCSCAN(int arr[], int n, int head) {
    vector<int> temp;
    for (int i = 0; i < n; i++) temp.push_back(arr[i]);
    
    temp.push_back(0);
    temp.push_back(199);
    sort(temp.begin(), temp.end());

    int index = 0;
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] == head) {
            index = i;
            break;
        }
    }

    int total_movement = 0;
    cout << "C-SCAN Sequence: ";

    for (int i = index; i < temp.size(); i++) {
        cout << temp[i] << " ";
        if (i > index) total_movement += (temp[i] - temp[i - 1]);
    }

    total_movement += (199 - 0);

    for (int i = 0; i < index; i++) {
        cout << temp[i] << " ";
        if (i == 0) total_movement += temp[i];
        else total_movement += (temp[i] - temp[i - 1]);
    }

    cout << "\nTotal Movement: " << total_movement << "\n\n";
}

void runCLOOK(int arr[], int n, int head) {
    vector<int> temp;
    for (int i = 0; i < n; i++) temp.push_back(arr[i]);
    
    sort(temp.begin(), temp.end());

    int index = 0;
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] == head) {
            index = i;
            break;
        }
    }

    int total_movement = 0;
    cout << "C-LOOK Sequence: ";

    for (int i = index; i < temp.size(); i++) {
        cout << temp[i] << " ";
        if (i > index) total_movement += (temp[i] - temp[i - 1]);
    }

    total_movement += (temp.back() - temp.front());

    for (int i = 0; i < index; i++) {
        cout << temp[i] << " ";
        if (i > 0) total_movement += (temp[i] - temp[i - 1]);
    }

    cout << "\nTotal Movement: " << total_movement << "\n";
}

int main() {
    int queue[] = {98, 183, 37, 122, 14, 124, 65, 67, 53};
    int n = sizeof(queue) / sizeof(queue[0]);
    int head = 53;

    cout << "Disk Scheduling Algorithms\n";
    cout << "--------------------------\n";
    
    runCSCAN(queue, n, head);
    runCLOOK(queue, n, head);

    return 0;
}
