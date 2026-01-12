#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    bool is_completed;
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
        processes[i].is_completed = false;
    }

    sort(processes.begin(), processes.end(), compareAT);

    int current_time = 0;
    int completed_processes_count = 0;
    
    // Sort logic handled dynamically or we can loop to find best
    // For simplicity and standard exam implementation, we loop through all to find best candidate
    
    // To print in order of execution or ID? Usually ID table is final output. 
    // We will store result in a separate list or just update struct.
    
    while(completed_processes_count < number_of_processes) {
        int process_index = -1;
        int minimum_burst_time = 1000000; // Large number

        for(int i=0; i<number_of_processes; i++) {
            if(processes[i].arrival_time <= current_time && !processes[i].is_completed) {
                if(processes[i].burst_time < minimum_burst_time) {
                    minimum_burst_time = processes[i].burst_time;
                    process_index = i;
                }
            }
        }

        if(process_index != -1) {
            processes[process_index].completion_time = current_time + processes[process_index].burst_time;
            processes[process_index].turnaround_time = processes[process_index].completion_time - processes[process_index].arrival_time;
            processes[process_index].waiting_time = processes[process_index].turnaround_time - processes[process_index].burst_time;
            processes[process_index].is_completed = true;
            current_time = processes[process_index].completion_time;
            completed_processes_count++;
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
