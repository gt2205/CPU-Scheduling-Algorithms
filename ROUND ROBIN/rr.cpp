#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Structure to represent a process
struct Process {
    int arrival;     // Arrival time of the process
    int burst;       // Burst time of the process
    int rem_burst;   // Remaining burst time of the process
    int completion;  // Completion time of the process
    int waiting;     // Waiting time of the process
    int turnaround;  // Turnaround time of the process
};

// Comparator to sort processes by arrival time, then by burst time
struct cmp {
    bool operator()(Process &a, Process &b) {
        if (a.arrival != b.arrival)
            return a.arrival < b.arrival;
        return a.burst < b.burst;
    }
};

// Function to perform Round Robin (RR) scheduling
void rr(vector<Process> &processes) {
    int i = 0;
    int n = processes.size();
    deque<int> dq;  // Deque to manage the processes in RR scheduling
    int time = 0;   // Current time
    int time_quantum = 2;  // Time quantum for RR

    // Continue until all processes are handled
    while (i < n || !dq.empty()) {
        // Add processes to the deque that have arrived by the current time
        while (i < n && processes[i].arrival <= time) {
            dq.push_back(i);
            i++;
        }

        // If no processes are in the deque, advance time to the next arrival
        if (dq.empty()) {
            time = processes[i].arrival;
            continue;
        }

        // Get the process at the front of the deque
        int front = dq.front();
        dq.pop_front();

        // Check if the remaining burst time is less than or equal to the time quantum
        if (processes[front].rem_burst <= time_quantum) {
            time += processes[front].rem_burst;  // Advance time by the remaining burst time
            processes[front].rem_burst = 0;  // Process is completed
            processes[front].completion = time;  // Set completion time
            processes[front].turnaround = processes[front].completion - processes[front].arrival;  // Calculate turnaround time
            processes[front].waiting = processes[front].turnaround - processes[front].burst;  // Calculate waiting time
        } else {
            // If the remaining burst time is greater than the time quantum, execute for the time quantum
            processes[front].rem_burst -= time_quantum;  // Decrease the remaining burst time
            time += time_quantum;  // Advance time by the time quantum
            dq.push_back(front);  // Re-add the process to the back of the deque
        }
    }
}

int main() {
    int n;
    cout << "Number of processes: ";
    cin >> n;
    vector<Process> processes(n);

    // Input process details
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << " -\n";
        cout << "Arrival time: ";
        cin >> processes[i].arrival;
        cout << "Burst time: ";
        cin >> processes[i].burst;
        processes[i].rem_burst = processes[i].burst;  // Initialize remaining burst time
    }

    // Sort processes by arrival time, then by burst time
    sort(processes.begin(), processes.end(), cmp());

    // Perform Round Robin scheduling
    rr(processes);

    // Output the results
    cout << "\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t\t" << processes[i].arrival << "\t\t"
             << processes[i].burst << "\t\t" << processes[i].completion << "\t\t\t"
             << processes[i].turnaround << "\t\t\t\t" << processes[i].waiting << "\t\n";
    }

    return 0;
}
