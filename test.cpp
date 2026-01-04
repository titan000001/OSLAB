#include<iostream>
using namespace std;

struct Process{
    int id;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
};

void calculateRoundRobin(Process processes[], int processCount, int timeQuantum){
    int currentTime = 0;
    int completedProcess = 0;

    while(completedProcess < processCount){
        bool workDoneInPass = false;
        
    }
}

int main(){
    Process proc[] = {
        {1, 10, 10, 0, 0},
        {2, 5, 5, 0, 0},
        {3, 8, 8, 0, 0}
    };

    int processCount = sizeof(proc)/sizeof(proc[0]);
    int timeQuantum = 2;

    calculateRoundRobin(proc, processCount, timeQuantum);

    return 0;
    
}