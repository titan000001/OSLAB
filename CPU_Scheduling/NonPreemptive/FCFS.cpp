#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Process {
    int process_id;
    int arrival_time; // Arrival Time
    int burst_time; // Burst Time
    int completion_time; // Completion Time
    int turnaround_time; // Turn Around Time
    int waiting_time; // Waiting Time
};

bool compareAT(Process a, Process b) {
    return a.arrival_time < b.arrival_time;
}

int main() {
    int number_of_processes;
    cout << "Enter number of processes: ";
    cin >> number_of_processes;

    vector<Process> processes(number_of_processes);
    cout << "Enter Arrival Time and Burst Time for each process:\n";
    for (int i = 0; i < number_of_processes; i++) {
        processes[i].process_id = i + 1;
        cout << "P" << i + 1 << ": ";
        cin >> processes[i].arrival_time >> processes[i].burst_time;
    }

    sort(processes.begin(), processes.end(), compareAT);

    int current_time = 0;
    for (int i = 0; i < number_of_processes; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        processes[i].completion_time = current_time + processes[i].burst_time;
        current_time = processes[i].completion_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }

    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < number_of_processes; i++) {
        cout << "P" << processes[i].process_id << "\t" << processes[i].arrival_time << "\t" << processes[i].burst_time << "\t" << processes[i].completion_time << "\t" << processes[i].turnaround_time << "\t" << processes[i].waiting_time << endl;
    }

    float average_turnaround_time = 0, average_waiting_time = 0;
    for(int i=0; i<number_of_processes; i++){
        average_turnaround_time += processes[i].turnaround_time;
        average_waiting_time += processes[i].waiting_time;
    }

    cout << "\nAverage Output:\n";
    cout << "Average Turn Around Time: " << average_turnaround_time/number_of_processes << endl;
    cout << "Average Waiting Time: " << average_waiting_time/number_of_processes << endl;

    return 0;
}
