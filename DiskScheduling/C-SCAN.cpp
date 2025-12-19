#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int arr[] = {98, 183, 37, 122, 14, 124, 65, 67, 53, 0, 199}; 
    int n = 11; 
    int head = 53;
    int total_movement = 0;


    sort(arr, arr + n);


    int index;
    for (int i = 0; i < n; i++) {
        if (arr[i] == head) {
            index = i;
            break;
        }
    }

    cout << "Sequence: ";


    for (int i = index; i < n; i++) {
        cout << arr[i] << " ";
        if (i > index) {
            total_movement += (arr[i] - arr[i - 1]);
        }
    }

    total_movement += (199 - 0); 


    for (int i = 0; i < index; i++) {
        cout << arr[i] << " ";
        if (i == 0) {
            total_movement += (arr[i] - 0);
        } else {
            total_movement += (arr[i] - arr[i - 1]);
        }
    }

    cout << "\nTotal Head Movement: " << total_movement << endl;

    return 0;
}
