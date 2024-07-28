#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Structure to represent a process
struct Process {
  int arrival;     // Arrival time of the process
  int burst;       // Burst time of the process
  int completion;  // Completion time of the process
  int waiting;     // Waiting time of the process
  int turnaround;  // Turnaround time of the process
};

// Comparator to sort processes by arrival time, and then by burst time
struct cmp {
  bool operator()(Process &a, Process &b) {
    if (a.arrival != b.arrival)
      return a.arrival < b.arrival;
    return a.burst < b.burst;
  }
};

// Comparator for the priority queue to sort processes by burst time
struct cmp1 {
  bool operator()(Process &a, Process &b) { return a.burst > b.burst; }
};

// Function to perform SJF Non-Preemptive scheduling
void sjf(vector<Process> &processes) {
  // Priority queue to select the process with the shortest burst time
  priority_queue<Process, vector<Process>, cmp1> pq;

  int t = processes[0].arrival;  // Current time
  int i = 0;                     // Index for processes
  while (i < processes.size() || !pq.empty()) {
    // Push all processes that have arrived by current time into the priority queue
    while (i < processes.size() && processes[i].arrival <= t) {
      pq.push(processes[i]);
      i++;
    }

    // If no process is in the priority queue, move time to the next process arrival time
    if (pq.empty()) {
      t = processes[i].arrival;
      continue;
    }

    // Get the process with the shortest burst time
    Process current = pq.top();
    pq.pop();

    // Update current time, completion, turnaround, and waiting times
    t += current.burst;
    current.completion = t;
    current.turnaround = current.completion - current.arrival;
    current.waiting = current.turnaround - current.burst;

    // Update the process information in the original process list
    for (auto &p : processes) {
      if (p.arrival == current.arrival && p.burst == current.burst && p.completion == 0) {
        p.completion = current.completion;
        p.turnaround = current.turnaround;
        p.waiting = current.waiting;
        break;
      }
    }
  }
}

int main() {
  int n;  // Number of processes
  cout << "Number of processes: ";
  cin >> n;
  vector<Process> processes(n);

  // Input arrival and burst times for each process
  for (int i = 0; i < n; i++) {
    cout << "Process " << i + 1 << " -\n";
    cout << "Arrival time: ";
    cin >> processes[i].arrival;
    cout << "Burst time: ";
    cin >> processes[i].burst;
  }

  // Sort processes by arrival time and burst time
  sort(processes.begin(), processes.end(), cmp());

  // Perform SJF Non-Preemptive scheduling
  sjf(processes);

  // Output the scheduling results
  cout << "\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
  for (int i = 0; i < n; i++) {
    cout << "P" << i + 1 << "\t\t" << processes[i].arrival << "\t\t"
         << processes[i].burst << "\t\t" << processes[i].completion << "\t\t\t"
         << processes[i].turnaround << "\t\t\t\t" << processes[i].waiting
         << "\t\n";
  }

  return 0;
}
