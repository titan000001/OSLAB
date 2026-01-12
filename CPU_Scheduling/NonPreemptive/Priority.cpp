#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Process {
    int id;
    int at;
    int bt;
    int priority;
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
    cout << "Enter Arrival Time, Burst Time, and Priority (Lower value = Higher Priority) for each process:\n";
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cout << "P" << i + 1 << ": ";
        cin >> p[i].at >> p[i].bt >> p[i].priority;
        p[i].completed = false;
    }

    int currentTime = 0;
    int completed = 0;

    while(completed < n) {
        int idx = -1;
        int minPriority = 1000000; // Large number

        for(int i=0; i<n; i++) {
            if(p[i].at <= currentTime && !p[i].completed) {
                if(p[i].priority < minPriority) {
                    minPriority = p[i].priority;
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

    cout << "\nProcess\tAT\tBT\tPri\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].id << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].priority << "\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << endl;
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
