#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Define a class to represent a process in the scheduling algorithm
class Process {
public:
  int arrival;     // Arrival time of the process
  int burst;       // Burst time (CPU time required) of the process
  int completion;  // Completion time of the process
  int turnaround;  // Turnaround time of the process
  int waiting;     // Waiting time of the process

  // Constructor to initialize a process with arrival and burst times
  Process(int a, int b)
      : arrival(a), burst(b), completion(0), turnaround(0), waiting(0) {}
};

// Define a comparator for sorting processes
struct cmp {
  // Comparator function to sort processes based on arrival time,
  // and if arrival times are equal, sort by burst time
  bool operator()(Process &a, Process &b) {
    if (a.arrival != b.arrival)
      return a.arrival < b.arrival;
    return a.burst < b.burst;
  }
};

// Function to perform First-Come, First-Served (FCFS) scheduling
void fcfs(vector<Process> &processes) {
  int t = processes[0].arrival; // Initialize current time to the arrival time of the first process
  float wait = 0, turnaround = 0;

  for (int i = 0; i < processes.size(); i++) {
    if (t < processes[i].arrival) {
      t = processes[i].arrival; // Update current time if there is an idle period
    }

    // Calculate completion, turnaround, and waiting times for each process
    processes[i].completion = t + processes[i].burst;
    processes[i].turnaround = processes[i].completion - processes[i].arrival;
    processes[i].waiting = processes[i].turnaround - processes[i].burst;
    t = processes[i].completion; // Update current time to the completion time of the current process
  }
}

int main() {
  int n; // Number of processes
  cout << "No of processes:" << endl;
  cin >> n; // Input the number of processes
  vector<Process> processes; // Vector to store the processes

  // Input arrival and burst times for each process
  for (int i = 0; i < n; i++) {
    int arrival, burst;
    cout << "Process " << i + 1 << " -\n";
    cout << "Arrival time: ";
    cin >> arrival;
    cout << "Burst time: ";
    cin >> burst;
    processes.emplace_back(arrival, burst); // Create a new process and add it to the vector
  }

  // Sort the processes based on arrival time (and burst time if arrival times are equal)
  sort(processes.begin(), processes.end(), cmp());

  // Perform FCFS scheduling on the sorted processes
  fcfs(processes);

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
