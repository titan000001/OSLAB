#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Process {
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    bool completed;
};

bool compareAT(Process a, Process b) {
    return a.at < b.at;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> p(n);
    cout << "Enter Arrival Time and Burst Time for each process:\n";
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cout << "P" << i + 1 << ": ";
        cin >> p[i].at >> p[i].bt;
        p[i].completed = false;
    }

    sort(p.begin(), p.end(), compareAT);

    int currentTime = 0;
    int completed = 0;
    
    // Sort logic handled dynamically or we can loop to find best
    // For simplicity and standard exam implementation, we loop through all to find best candidate
    
    // To print in order of execution or ID? Usually ID table is final output. 
    // We will store result in a separate list or just update struct.
    
    while(completed < n) {
        int idx = -1;
        int minBT = 1000000; // Large number

        for(int i=0; i<n; i++) {
            if(p[i].at <= currentTime && !p[i].completed) {
                if(p[i].bt < minBT) {
                    minBT = p[i].bt;
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            p[idx].ct = currentTime + p[idx].bt;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].completed = true;
            currentTime = p[idx].ct;
            completed++;
        } else {
            currentTime++;
        }
    }

    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].id << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << endl;
    }
    
    float avgTAT = 0, avgWT = 0;
    for(int i=0; i<n; i++){
        avgTAT += p[i].tat;
        avgWT += p[i].wt;
    }
    
    cout << "\nAverage Output:\n";
    cout << "Average Turn Around Time: " << avgTAT/n << endl;
    cout << "Average Waiting Time: " << avgWT/n << endl;

    return 0;
}
