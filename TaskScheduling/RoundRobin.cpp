#include <iostream>

using namespace std;

struct Process {
    int id;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
};

void calculateRoundRobin(Process processes[], int processCount, int timeQuantum) {
    int currentTime = 0;
    int completedProcesses = 0;
    
    // Continue until all processes are completed
    while (completedProcesses < processCount) {
        bool workDoneInPass = false;
        
        for (int i = 0; i < processCount; i++) {
            if (processes[i].remainingTime > 0) {
                workDoneInPass = true;
                
                if (processes[i].remainingTime > timeQuantum) {
                    currentTime += timeQuantum;
                    processes[i].remainingTime -= timeQuantum;
                } else {
                    currentTime += processes[i].remainingTime;
                    processes[i].waitingTime = currentTime - processes[i].burstTime;
                    processes[i].remainingTime = 0;
                    completedProcesses++;
                }
            }
        }
        
        // Safety break if no work was done in a full pass (should not happen if logic is correct)
        if (!workDoneInPass) break;
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
        {1, 10, 10, 0, 0},
        {2, 5, 5, 0, 0},
        {3, 8, 8, 0, 0}
    };
    int processCount = sizeof(proc) / sizeof(proc[0]);
    int timeQuantum = 2;

    calculateRoundRobin(proc, processCount, timeQuantum);

    return 0;
}
