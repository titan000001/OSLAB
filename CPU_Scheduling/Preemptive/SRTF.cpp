#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

struct Process {
    int id;
    int at;
    int bt;
    int rem_bt;
    int ct;
    int tat;
    int wt;
    bool completed;
};

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
        p[i].rem_bt = p[i].bt;
        p[i].completed = false;
    }

    int currentTime = 0;
    int completed = 0;

    // Simulation loop: increment time by 1 and check minimal remaining time
    while(completed < n) {
        int idx = -1;
        int minRem = INT_MAX;

        for(int i=0; i<n; i++) {
            if(p[i].at <= currentTime && !p[i].completed) {
                if(p[i].rem_bt < minRem) {
                    minRem = p[i].rem_bt;
                    idx = i;
                }
                // Tie-breaking: FCFS usually, or just keep first found
                if(p[i].rem_bt == minRem) {
                     if(p[i].at < p[idx].at) idx = i;
                }
            }
        }

        if(idx != -1) {
            p[idx].rem_bt--;
            currentTime++;
            
            if(p[idx].rem_bt == 0) {
                p[idx].ct = currentTime;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                p[idx].completed = true;
                completed++;
            }
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
