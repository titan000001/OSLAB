#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

bool compareBurst(Process a, Process b) {
    return a.burst_time < b.burst_time;
}

void sjf_scheduling(Process proc[], int n) {
    sort(proc, proc + n, compareBurst);

    proc[0].waiting_time = 0;

    for (int i = 1; i < n; i++) {
        proc[i].waiting_time = proc[i-1].burst_time + proc[i-1].waiting_time;
    }

    for (int i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].burst_time + proc[i].waiting_time;
    }

    cout << "--- SJF Task Scheduling Algorithm (Non-Preemptive) ---" << endl;
    cout << "Process ID | Burst Time | Waiting Time | Turnaround Time" << endl;
    cout << "--------------------------------------------------------" << endl;

    int total_wt = 0;
    int total_tat = 0;

    for (int i = 0; i < n; i++) {
        total_wt += proc[i].waiting_time;
        total_tat += proc[i].turnaround_time;
        
        cout << "    " << proc[i].id << "      |     " 
             << proc[i].burst_time << "      |      " 
             << proc[i].waiting_time << "       |        " 
             << proc[i].turnaround_time << endl;
    }

    cout << "--------------------------------------------------------" << endl;
    cout << "Average Waiting Time: " << (float)total_wt / n << endl;
    cout << "Average Turnaround Time: " << (float)total_tat / n << endl;
}

int main() {
    Process processes[] = {
        {1, 6, 0, 0},
        {2, 8, 0, 0},
        {3, 7, 0, 0},
        {4, 3, 0, 0}
    };
    int n = sizeof(processes) / sizeof(processes[0]);

    sjf_scheduling(processes, n);

    return 0;
}
