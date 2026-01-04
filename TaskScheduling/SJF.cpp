#include <iostream>

#include <algorithm>

using namespace std;

struct Process {
    int id;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

// Comparator function to sort processes by burst time (SJF logic)
bool compareBurstTime(Process a, Process b) {
    return a.burstTime < b.burstTime;
}

void calculateSJF(Process processes[], int processCount) {
    // Sort processes by burst time for Shortest Job First
    sort(processes, processes + processCount, compareBurstTime);

    processes[0].waitingTime = 0; // First process has 0 waiting time

    // Calculate waiting time for each process
    for (int i = 1; i < processCount; i++) {
        processes[i].waitingTime = processes[i - 1].burstTime + processes[i - 1].waitingTime;
    }

    float totalWaitingTime = 0;
    float totalTurnaroundTime = 0;

    cout << "ProcessID\t| BurstTime\t| WaitingTime\t| TurnAroundTime" << endl;
    
    // Calculate turnaround time and print details for each process
    for (int i = 0; i < processCount; i++) {
        processes[i].turnaroundTime = processes[i].burstTime + processes[i].waitingTime;
        
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
        
        cout << processes[i].id << "\t\t| " << processes[i].burstTime << "\t\t| " << processes[i].waitingTime << "\t\t| " << processes[i].turnaroundTime << endl;
    }

    cout << "\nAverage Waiting Time: " << totalWaitingTime / processCount << endl;
    cout << "Average Turnaround Time: " << totalTurnaroundTime / processCount << endl;
}

int main() {
    Process proc[] = {
        {1, 6, 0, 0},
        {2, 8, 0, 0},
        {3, 7, 0, 0},
        {4, 3, 0, 0}
    };
    int processCount = sizeof(proc) / sizeof(proc[0]);

    calculateSJF(proc, processCount);

    return 0;
}
