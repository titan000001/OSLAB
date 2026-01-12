#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Process {
    int id;
    int at;
    int bt;
    int rem_bt;
    int ct;
    int tat;
    int wt;
};

bool compareAT(Process a, Process b) {
    return a.at < b.at;
}

int main() {
    int n, tq;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter Time Quantum: ";
    cin >> tq;

    vector<Process> p(n);
    cout << "Enter Arrival Time and Burst Time for each process:\n";
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cout << "P" << i + 1 << ": ";
        cin >> p[i].at >> p[i].bt;
        p[i].rem_bt = p[i].bt;
    }

    sort(p.begin(), p.end(), compareAT);

    int currentTime = 0;
    int completed = 0;
    
    // Using a simple loop approach instead of a complex queue for simplicity in exam
    // We repeatedly iterate through processes to find available ones
    // Note: A proper queue is better for strict RR, but cyclic check is often accepted for simple demos if AT is handled carefully.
    // However, strictly, RR uses a Ready Queue. Let's implement with a basic checking loop that simulates a queue behavior or just use a queue.
    // To keep it "simple" and "similar style", let's use the cyclic iteration but be careful about AT.
    
    // Actually, queue is safest for correctness of "Arrival Order".
    // But to match the "Simple" request, let's try the infinite loop with "visited" check or just a queue.
    // Let's use a queue, it is the standard way.
    
    vector<int> q;
    vector<bool> inQueue(n, false);
    
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
    q.push_back(0); // Assuming sorted and p[0] arrives at 0 or we jump time
    inQueue[0] = true;
    
    if (p[0].at > 0) {
        // Handle case where first process doesn't start at 0
        currentTime = p[0].at;
    }
    
    while(completed < n) {
        if (q.empty()) {
            // No process in queue, jump to next arrival or increment
            bool found = false;
            for(int i=0; i<n; i++) {
                if(p[i].rem_bt > 0) {
                     // Find next arriving
                     // Actually, if queue is empty and processes remain, we just need to advance time to next AT
                     // For simplicity, just increment time
                     currentTime++;
                     found = true;
                     break; 
                }
            }
            if(!found) break; // Should not happen if completed < n
            
            // Checks for new arrivals after increment
            for(int i = 0; i < n; i++) {
                 if(p[i].at <= currentTime && p[i].rem_bt > 0 && !inQueue[i]){
                     q.push_back(i);
                     inQueue[i] = true;
                 }
            }
            continue;
        }
        
        int curr = q[0];
        q.erase(q.begin());
        
        int time_spent = min(tq, p[curr].rem_bt);
        p[curr].rem_bt -= time_spent;
        currentTime += time_spent;
        
        // Add new arrivals
        for(int i = 0; i < n; i++) {
            if(p[i].at <= currentTime && p[i].rem_bt > 0 && !inQueue[i]) {
                q.push_back(i);
                inQueue[i] = true;
            }
        }
        
        if(p[curr].rem_bt > 0) {
            q.push_back(curr);
        } else {
            p[curr].ct = currentTime;
            p[curr].tat = p[curr].ct - p[curr].at;
            p[curr].wt = p[curr].tat - p[curr].bt;
            completed++;
        }
    }

    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].id << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << endl;
    }

    float avgTAT = 0, avgWT = 0;
    for(int i=0; i<n; i++){
        avgTAT += p[i].tat;
        avgWT += p[i].wt;
    }

    cout << "\nAverage Output:\n";
    cout << "Average Turn Around Time: " << avgTAT/n << endl;
    cout << "Average Waiting Time: " << avgWT/n << endl;

    return 0;
}
