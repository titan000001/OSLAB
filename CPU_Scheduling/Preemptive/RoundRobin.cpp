#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

bool compareAT(Process a, Process b) {
    return a.arrival_time < b.arrival_time;
}

int main() {
    int number_of_processes, time_quantum;
    cout << "Enter number of processes: ";
    cin >> number_of_processes;
    cout << "Enter Time Quantum: ";
    cin >> time_quantum;

    vector<Process> processes(number_of_processes);
    cout << "Enter Arrival Time and Burst Time for each process:\n";
    for (int i = 0; i < number_of_processes; i++) {
        processes[i].process_id = i + 1;
        cout << "P" << i + 1 << ": ";
        cin >> processes[i].arrival_time >> processes[i].burst_time;
        processes[i].remaining_burst_time = processes[i].burst_time;
    }

    sort(processes.begin(), processes.end(), compareAT);

    int current_time = 0;
    int completed_processes_count = 0;
    
    // Using a simple loop approach instead of a complex queue for simplicity in exam
    // We repeatedly iterate through processes to find available ones
    // Note: A proper queue is better for strict RR, but cyclic check is often accepted for simple demos if AT is handled carefully.
    // However, strictly, RR uses a Ready Queue. Let's implement with a basic checking loop that simulates a queue behavior or just use a queue.
    // To keep it "simple" and "similar style", let's use the cyclic iteration but be careful about AT.
    
    // Actually, queue is safest for correctness of "Arrival Order".
    // But to match the "Simple" request, let's try the infinite loop with "visited" check or just a queue.
    // Let's use a queue, it is the standard way.
    
    vector<int> ready_queue;
    vector<bool> is_in_queue(number_of_processes, false);
    
    // Push first process(es)
    // We need to handle time advancement carefully.
    
    // Alternative Simple Implementation:
    // Loop until completed == n
    // Inside, pick valid process from queue. 
    // If queue empty, increment time.
    
    // Let's stick to the prompt's request for "simple" and "similar style".
    // The previous ones (SJF, Priority) used a "find best candidate" loop.
    // RR doesn't find best, it takes head of queue.
    
    // Let's go with the standard Queue approach.
    int idx = 0; // index to add new processes
    ready_queue.push_back(0); // Assuming sorted and p[0] arrives at 0 or we jump time
    is_in_queue[0] = true;
    
    if (processes[0].arrival_time > 0) {
        // Handle case where first process doesn't start at 0
        current_time = processes[0].arrival_time;
    }
    
    while(completed_processes_count < number_of_processes) {
        if (ready_queue.empty()) {
            // No process in queue, jump to next arrival or increment
            bool found = false;
            for(int i=0; i<number_of_processes; i++) {
                if(processes[i].remaining_burst_time > 0) {
                     // Find next arriving
                     // Actually, if queue is empty and processes remain, we just need to advance time to next AT
                     // For simplicity, just increment time
                     current_time++;
                     found = true;
                     break; 
                }
            }
            if(!found) break; // Should not happen if completed < n
            
            // Checks for new arrivals after increment
            for(int i = 0; i < number_of_processes; i++) {
                 if(processes[i].arrival_time <= current_time && processes[i].remaining_burst_time > 0 && !is_in_queue[i]){
                     ready_queue.push_back(i);
                     is_in_queue[i] = true;
                 }
            }
            continue;
        }
        
        int current_process_index = ready_queue[0];
        ready_queue.erase(ready_queue.begin());
        
        int time_spent = min(time_quantum, processes[current_process_index].remaining_burst_time);
        processes[current_process_index].remaining_burst_time -= time_spent;
        current_time += time_spent;
        
        // Add new arrivals
        for(int i = 0; i < number_of_processes; i++) {
            if(processes[i].arrival_time <= current_time && processes[i].remaining_burst_time > 0 && !is_in_queue[i]) {
                ready_queue.push_back(i);
                is_in_queue[i] = true;
            }
        }
        
        if(processes[current_process_index].remaining_burst_time > 0) {
            ready_queue.push_back(current_process_index);
        } else {
            processes[current_process_index].completion_time = current_time;
            processes[current_process_index].turnaround_time = processes[current_process_index].completion_time - processes[current_process_index].arrival_time;
            processes[current_process_index].waiting_time = processes[current_process_index].turnaround_time - processes[current_process_index].burst_time;
            completed_processes_count++;
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
