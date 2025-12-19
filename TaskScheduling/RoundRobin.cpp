#include <iostream>

using namespace std;

struct Process {
    int id;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

void round_robin(Process proc[], int n, int quantum) {
    int time = 0;
    int completed = 0;
    
    while (completed < n) {
        bool work_done_in_pass = false;
        
        for (int i = 0; i < n; i++) {
            if (proc[i].remaining_time > 0) {
                work_done_in_pass = true;
                
                if (proc[i].remaining_time > quantum) {
                    time += quantum;
                    proc[i].remaining_time -= quantum;
                } else {
                    time += proc[i].remaining_time;
                    proc[i].waiting_time = time - proc[i].burst_time;
                    proc[i].remaining_time = 0;
                    completed++;
                }
            }
        }
        
        if (!work_done_in_pass) break;
    }

    for (int i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].burst_time + proc[i].waiting_time;
    }

    cout << "--- Round Robin Task Scheduling Algorithm ---" << endl;
    cout << "Time Quantum: " << quantum << endl;
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
        {1, 10, 10, 0, 0},
        {2, 5, 5, 0, 0},
        {3, 8, 8, 0, 0}
    };
    int n = sizeof(processes) / sizeof(processes[0]);
    int quantum = 2;

    round_robin(processes, n, quantum);

    return 0;
}
