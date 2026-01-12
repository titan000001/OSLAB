#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Process {
    int process_id;
    int burst_time; // Burst Time
    int completion_time; // Completion Time
    int turnaround_time; // Turn Around Time
    int waiting_time; // Waiting Time
};

int main() {
    int number_of_processes;
    cout << "Enter number of processes: ";
    cin >> number_of_processes;

    vector<Process> processes(number_of_processes);
    cout << "Enter Burst Time for each process:\n";
    for (int i = 0; i < number_of_processes; i++) {
        processes[i].process_id = i + 1;
        cout << "P" << i + 1 << ": ";
        cin >> processes[i].burst_time;
    }

    int current_time = 0;
    for (int i = 0; i < number_of_processes; i++) {
        processes[i].completion_time = current_time + processes[i].burst_time;
        current_time = processes[i].completion_time;
        processes[i].turnaround_time = processes[i].completion_time; // Arrival time is 0
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }

    cout << "\nProcess\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < number_of_processes; i++) {
        cout << "P" << processes[i].process_id << "\t" << processes[i].burst_time << "\t" << processes[i].completion_time << "\t" << processes[i].turnaround_time << "\t" << processes[i].waiting_time << endl;
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
