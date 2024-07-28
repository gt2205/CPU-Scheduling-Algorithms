#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Structure to represent a process
struct Process {
  int arrival;    // Arrival time of the process
  int burst;      // Burst time of the process
  int completion; // Completion time of the process
  int rem_burst;  // Remaining burst time of the process
  int waiting;    // Waiting time of the process
  int turnaround; // Turnaround time of the process
};

// Comparator to sort processes by arrival time, then by burst time
struct cmp {
  bool operator()(Process &a, Process &b) {
    if (a.arrival != b.arrival)
      return a.arrival < b.arrival;
    return a.burst < b.burst;
  }
};

// Comparator to sort processes by remaining burst time (for SJF Preemptive)
struct cmp1 {
  bool operator()(Process &a, Process &b) { return a.rem_burst > b.rem_burst; }
};

// Function to perform Shortest Job First (SJF) Preemptive scheduling
void sjf(vector<Process> &processes) {
  // Priority queue to get the process with the shortest remaining burst time
  priority_queue<Process, vector<Process>, cmp1> pq;

  // Initialize time with the arrival time of the first process
  int t = processes[0].arrival;
  int time_quantum; // Time for which process can safely execute as no process
                    // with lower burst time is present
  int i = 0;        // Index to keep track of the processes

  // Continue until all processes are handled
  while (i < processes.size() || !pq.empty()) {
    // Add processes to the priority queue that have arrived by the current time
    while (i < processes.size() && processes[i].arrival <= t) {
      pq.push(processes[i]);
      i++;
    }

    // If no processes are in the priority queue, advance time to the next
    // arrival
    if (pq.empty()) {
      t = processes[i].arrival;
      continue;
    }

    if (i < processes.size()) {
      time_quantum = processes[i].arrival - t;
    } else {
      time_quantum = INT_MAX;
    }

    // Get the process with the shortest burst time
    Process current = pq.top();
    pq.pop();

    // Check if the remaining burst time is less than or equal to the time
    // quantum
    if (current.rem_burst <= time_quantum) {
      t += current.rem_burst; // Advance time by the remaining burst time
      current.rem_burst = 0;  // Process is completed
      current.completion = t; // Set completion time
      current.turnaround = current.completion - current.arrival; // Calculate turnaround time
      current.waiting = current.turnaround - current.burst; // Calculate waiting time

      // Update the original process list with the completion, turnaround, and
      // waiting times
      for (auto &p : processes) {
        if (p.arrival == current.arrival && p.burst == current.burst && p.completion == 0) {
          p.completion = current.completion;
          p.turnaround = current.turnaround;
          p.waiting = current.waiting;
          break;
        }
      }
    } else {
      // If the remaining burst time is greater than the time quantum, execute
      // for the time quantum
      t += time_quantum;
      current.rem_burst -= time_quantum; // Decrease the remaining burst time
      pq.push(current); // Re-add the process to the priority queue
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
    processes[i].rem_burst = processes[i].burst; // Initialize remaining burst time
  }

  // Sort processes by arrival time, then by burst time
  sort(processes.begin(), processes.end(), cmp());

  // Perform SJF scheduling
  sjf(processes);

  // Output the results
  cout << "\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
  for (int i = 0; i < n; i++) {
    cout << "P" << i + 1 << "\t\t" << processes[i].arrival << "\t\t"
         << processes[i].burst << "\t\t" << processes[i].completion << "\t\t\t"
         << processes[i].turnaround << "\t\t\t\t" << processes[i].waiting << "\t\n";
  }

  return 0;
}
