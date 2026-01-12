#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    bool is_completed;
};

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
        processes[i].remaining_burst_time = processes[i].burst_time;
        processes[i].is_completed = false;
    }

    int current_time = 0;
    int completed_processes_count = 0;

    // Simulation loop: increment time by 1 and check minimal remaining time
    while(completed_processes_count < number_of_processes) {
        int process_index = -1;
        int minimum_remaining_time = INT_MAX;

        for(int i=0; i<number_of_processes; i++) {
            if(processes[i].arrival_time <= current_time && !processes[i].is_completed) {
                if(processes[i].remaining_burst_time < minimum_remaining_time) {
                    minimum_remaining_time = processes[i].remaining_burst_time;
                    process_index = i;
                }
                // Tie-breaking: FCFS usually, or just keep first found
                if(processes[i].remaining_burst_time == minimum_remaining_time) {
                     if(processes[i].arrival_time < processes[process_index].arrival_time) process_index = i;
                }
            }
        }

        if(process_index != -1) {
            processes[process_index].remaining_burst_time--;
            current_time++;
            
            if(processes[process_index].remaining_burst_time == 0) {
                processes[process_index].completion_time = current_time;
                processes[process_index].turnaround_time = processes[process_index].completion_time - processes[process_index].arrival_time;
                processes[process_index].waiting_time = processes[process_index].turnaround_time - processes[process_index].burst_time;
                processes[process_index].is_completed = true;
                completed_processes_count++;
            }
        } else {
            current_time++;
        }
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
